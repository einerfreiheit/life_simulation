#include "../OpenGL/OpenGLRender.h"

#include <string>
#include "../OpenGL/OpenGLBufferFactory.h"
#include <iostream>
#include "../OpenGL/ShadersUtils.h"

GLFWwindow* OpenGLRender::window = NULL;

void OpenGLRender::checkError() {
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR) {
		throw std::runtime_error(std::to_string(errorCode));
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

	OpenGLBufferFactory::buildBuffers(staticBuffers, dynamicBuffers);
	for (auto buffer : staticBuffers) {
		buffer->initBuffer(world);
		buffer->updateBuffer(world);
	}
	for (auto buffer : dynamicBuffers) {
		buffer->initBuffer(world);
	}


}

OpenGLRender::~OpenGLRender() {
	for (int i =0; i<staticBuffers.size();i++){
		delete staticBuffers[i];
	}
	for (int i =0; i<dynamicBuffers.size();i++){
			delete dynamicBuffers[i];
		}

}
void OpenGLRender::draw(World *world) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.2, 0.0f, 1.0f);
	glfwPollEvents();
	glUseProgram(shader);
	mvpMatrix = camera->getMVPMatrix();
	glUniformMatrix4fv(shaderMVP, 1, GL_FALSE, (&mvpMatrix[0][0]));
	glUniform1i(glGetUniformLocation(shader, "gSampler"), 0);

	glBindVertexArray(vertexAttributeObject);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	for (auto buffer : staticBuffers) {
		buffer->texture->bindTexture(GL_TEXTURE0);

		glBindBuffer(GL_ARRAY_BUFFER, buffer->vertexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->indexBufferObject);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) (3 * sizeof(float)));
		glDrawElements(GL_TRIANGLES, buffer->bufferData->indicesToUpate, GL_UNSIGNED_INT, 0);

	}
	for (auto buffer : dynamicBuffers) {

		buffer->updateBuffer(world);
		buffer->texture->bindTexture(GL_TEXTURE0);

		glBindBuffer(GL_ARRAY_BUFFER, buffer->vertexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->indexBufferObject);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (GLvoid*) (3 * sizeof(float)));
		glDrawElements(GL_TRIANGLES, buffer->bufferData->indicesToUpate, GL_UNSIGNED_INT, 0);

	}

	glBindTexture(GL_TEXTURE_2D,0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindVertexArray(0);
	glUseProgram(0);

	std::cout << glGetError() << " error ";

	glfwSwapBuffers(window);

}

