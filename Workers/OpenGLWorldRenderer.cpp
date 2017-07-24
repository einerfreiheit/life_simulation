#include "OpenGLWorldRenderer.h"
#define GLEW_STATIC
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <stdio.h>
#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Visualization/ShadersUtils.h"

static GLFWwindow* window = NULL;
static GLuint VAO, VBO;
static int mapWidth, mapHeight;

void checkOpenGLError() {
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR) {
		throw std::runtime_error(
				"OpenGL error:\n" + std::to_string(*gluErrorString(errorCode)));
	}
}

void OpenGLWorldRenderer::init() {
	if (glfwInit() != GL_TRUE) {
		throw std::runtime_error("GLFW init failed");
	}
	glfwWindowHint(GLFW_DEPTH_BITS, 16);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
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
	checkOpenGLError();
	std::cout << "openGl init done";
}

void OpenGLWorldRenderer::createMatrices() {
	float scaleF = 1.0 / 64;
	glm::vec3 mapCenter(-0.5 * mapWidth, -0.5 * mapHeight, 0.0f);
	model = glm::scale(model, glm::vec3(scaleF, scaleF, scaleF));
	model = glm::translate(model, mapCenter);
	model = glm::rotate(model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 6.5f), glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0), 4.0 / 3, 0.1, 100.0);

}
void OpenGLWorldRenderer::bindMatrices(GLuint shaderProgram) {
	mvpMatrixID = glGetUniformLocation(shaderProgram, "mvpMatrix");
	mvpMatrix = projection * view * model;

}

void OpenGLWorldRenderer::prepareMapData(World *world) {
	size_t size = 24 * mapHeight * mapWidth;
	std::vector<float> mapData;
	mapData.resize(size);

	mapDataPtr = mapData.data();

	std::cout << "allocated" << *mapDataPtr;
	float vertexZ;
	int offset;
	float vertexPosX;
	float vertexPosY;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			offset = 24 * (x + y * mapWidth);
			vertexZ = world->map[y][x].height;
			intensity = (vertexZ - minHeight) / (maxHeight - minHeight);
			vertexPosX = (float) x;
			vertexPosY = (float) y;
			*(mapDataPtr + offset) = vertexPosX;
			*(mapDataPtr + offset + 1) = vertexPosY;
			*(mapDataPtr + offset + 2) = vertexZ;
			*(mapDataPtr + offset + 3) = intensity;
			getTextureCoord(vertexPosX, vertexPosY, *(mapDataPtr + offset + 4),
					*(mapDataPtr + offset + 5));

			*(mapDataPtr + offset + 6) = vertexPosX;
			*(mapDataPtr + offset + 7) = (vertexPosY + 1.0);
			*(mapDataPtr + offset + 8) = vertexZ;
			*(mapDataPtr + offset + 9) = intensity;
			getTextureCoord(vertexPosX, vertexPosY + 1,
					*(mapDataPtr + offset + 10), *(mapDataPtr + offset + 11));

			*(mapDataPtr + offset + 12) = (vertexPosX + 1.0);
			*(mapDataPtr + offset + 13) = vertexPosY;
			*(mapDataPtr + offset + 14) = vertexZ;
			*(mapDataPtr + offset + 15) = intensity;
			getTextureCoord((vertexPosX + 1), vertexPosY,
					*(mapDataPtr + offset + 16), *(mapDataPtr + offset + 17));

			*(mapDataPtr + offset + 18) = (vertexPosX + 1.0);
			*(mapDataPtr + offset + 19) = (vertexPosY + 1.0);
			*(mapDataPtr + offset + 20) = vertexZ;
			*(mapDataPtr + offset + 21) = intensity;
			getTextureCoord((vertexPosX + 1), (vertexPosY + 1),
					*(mapDataPtr + offset + 22), *(mapDataPtr + offset + 23));

		}
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, mapData.size() * sizeof(float),
				mapData.data(),
				GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(GLvoid*) 0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(GLvoid*) (3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(GLvoid*) (4 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindVertexArray(0);

	}

}
OpenGLWorldRenderer::OpenGLWorldRenderer(World *world) {

	this->name = "OpenGlr";

	init();
	checkOpenGLError();
	shaderProgram = ShadersUtils::loadShaders("./shaders/vertex_shader_1.glsl",
			"./shaders/fragment_shader_1.glsl");
	mapHeight = world->map.size();
	mapWidth = world->map[0].size();
	bindMatrices(shaderProgram);
	setHeightDepth(world, maxHeight, minHeight);
	OpenGLControls::initControls(window);
	createMatrices();
	bindTextures();
	prepareMapData(world);

}

void OpenGLWorldRenderer::work(World* world) {
	if (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.2, 0.0f, 1.0f);
		glfwPollEvents();
		glUseProgram(shaderProgram);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture1"), 0);
		glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture2"), 1);
		view = OpenGLControls::computeViewMatrix(window);
		mvpMatrix = projection * view * model;

		glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, (&mvpMatrix[0][0]));

		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		for (int i = 0; i < mapHeight; i++) {


		}
		for (int i=0;i<mapHeight;i++){
		glDrawArrays(GL_TRIANGLE_STRIP, i*mapWidth*4,(mapWidth-1)*4);
		}
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);


		glfwSwapBuffers(window);
	}

}
OpenGLWorldRenderer::~OpenGLWorldRenderer() {

}

void OpenGLWorldRenderer::setHeightDepth(World *world, float &maxHeight,
		float &minHeight) {

	maxHeight = 0.0;
	minHeight = 0.0;
	float cellHeight = 0.0;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			cellHeight = world->map[i][j].height;
			maxHeight = std::max(maxHeight, cellHeight);
			minHeight = std::min(minHeight, cellHeight);
		}
	}

}
void OpenGLWorldRenderer::getTextureCoord(const float &vertexPosX,
		const float &vertexPosY, float &textureX, float &textureY) {

	textureX = ((int) vertexPosX % 64) / 64.0;
	textureY = ((int) vertexPosY % 64) / 64.0;
}
void OpenGLWorldRenderer::loadTexture(std::string filePath) {
	GLuint textureID = 0;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	unsigned char *image = SOIL_load_image(filePath.c_str(), &imageWidth,
			&imageHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB,
	GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

}
void OpenGLWorldRenderer::bindTextures() {
	glActiveTexture(GL_TEXTURE0);
	loadTexture("./textures/ground _1.jpg");
	glActiveTexture(GL_TEXTURE1);
	loadTexture("./textures/snow.jpg");
}
