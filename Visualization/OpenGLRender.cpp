#include "OpenGLRender.h"
#include <string>
#include "ShadersUtils.h"
#include <GLFW/glfw3.h>
#include  "OpenGLTexture.h"

#include <iostream>

GLFWwindow* OpenGLRender::window = NULL;
OpenGLTexture *mapTexture = NULL;
OpenGLTexture *waterTexture = NULL;
OpenGLTexture *creatureTexture = NULL;

void OpenGLRender::checkError() {
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR) {
		throw std::runtime_error("OpenGL error:\n" + std::to_string(*gluErrorString(errorCode)));
	}
}

void OpenGLRender::init() {

	if (glfwInit() != GL_TRUE) {
		throw std::runtime_error("GLFW init failed");
	}
	glfwWindowHint(GLFW_DEPTH_BITS, 16);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(1024, 768, "Output", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		throw std::runtime_error("Can't create GLFW window");
	}
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		throw std::runtime_error("GLEW init failed");
	}
	glEnable(GL_DEPTH_TEST);
	checkError();
	std::cout << "openGl init done";

}

OpenGLRender::OpenGLRender(World *world) {
	init();
	camera = new OpenGLCamera(window);
	glfwSetKeyCallback(window, camera->keyCallback);
	glfwSetCursorPosCallback(window, camera->cursorCallBack);
	glGenVertexArrays(1, &vertexAttributeObject);

	shader = ShadersUtils::loadShaders("./shaders/vertex_shader.glsl", "./shaders/fragment_shader.glsl");
	shaderMVP = glGetUniformLocation(shader, "mvpMatrix");
	shaderTexture = glGetUniformLocation(shader, "gSampler");

	staticData = new OpenGLStaticData;
	//glGenBuffers(1, &mapData);
	mapData = staticData->createData(world);
	dynamicData = new OpenGLDynamicData(world);
	mapData_ = new OpenGLMapData;
	mapData_->computeData(world);

	//glBindBuffer(GL_ARRAY_BUFFER, mapData);

	mapTexture = new OpenGLTexture(GL_TEXTURE_2D, "./textures/ground _1.jpg");
	mapTexture->loadTexture();
	creatureTexture = new OpenGLTexture(GL_TEXTURE_2D, "./textures/worm.jpg");
	creatureTexture->loadTexture();
	waterTexture = new OpenGLTexture(GL_TEXTURE_2D, "./textures/water.jpg");
	waterTexture->loadTexture();

}

OpenGLRender::~OpenGLRender() {

}
void OpenGLRender::draw(World *world) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.2, 0.0f, 1.0f);
	glfwPollEvents();
	glUseProgram(shader);
	dynamicData->updateBuffers(world);
	mvpMatrix = camera->getMVPMatrix();
	glUniformMatrix4fv(shaderMVP, 1, GL_FALSE, (&mvpMatrix[0][0]));

	mapTexture->bindTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(shader, "gSampler"), 0);

	glBindVertexArray(vertexAttributeObject);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, mapData);
	glBindBuffer(GL_ARRAY_BUFFER, mapData_->vertexBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,mapData_->indexBufferObject);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) (3 * sizeof(float)));

	glDrawElements(GL_TRIANGLES,mapData_->elementNumber,GL_UNSIGNED_INT,0);

//	for (int i = 0; i < world->map.size(); i++) {
	//	glDrawArrays(GL_TRIANGLE_STRIP, i * world->map[0].size() * 4, (world->map[0].size() - 1) * 4);
	//}


	glBindVertexArray(0);
	glBindVertexArray(vertexAttributeObject);

	waterTexture->bindTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(shader, "gSampler"), 0);
	glBindBuffer(GL_ARRAY_BUFFER, dynamicData->waterBuffer);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) (3 * sizeof(float)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,dynamicData->waterIBO);

	//for (int i = 0; i < dynamicData->waterBufferData.size() / 20; i++) {
		//glDrawArrays(GL_TRIANGLE_STRIP, 4*i, 4);
	//}
	//glDrawElements(GL_TRIANGLES,dynamicData->waterIndices.size(),GL_UNSIGNED_INT,0);

	dynamicData->water.clear();
	dynamicData->waterIndices.clear();
	creatureTexture->bindTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(shader, "gSampler"), 0);
	glBindBuffer(GL_ARRAY_BUFFER, dynamicData->creaturesBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) (3 * sizeof(float)));

	for (int i = 0; i < world->creatures.size(); i++) {
		glDrawArrays(GL_TRIANGLE_STRIP, 4 * i, 4);


	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindVertexArray(0);
	glUseProgram(0);

	glfwSwapBuffers(window);

}

