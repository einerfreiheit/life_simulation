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
static int mapWidth, mapHeight;

void checkOpenGLError() {
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR) {
		throw std::runtime_error(
				"OpenGL error:\n" + std::to_string(*gluErrorString(errorCode)));
	}
}

void OpenGLWorldRenderer::prepareCreaturesData(World *world) {
	float creatureZ = 0.01;
	Cell *cell = NULL;
	int heightGain;
	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			heightGain = 0;
			float fx = (float) x;
			float fy = (float) y;
			cell = &world->map[y][x];
			if (cell->water > 0.1) {
				float waterZ = cell->water + cell->height;
				water.push_back(fx);
				water.push_back(fy);
				water.push_back(waterZ);

				water.push_back(fx + 1);
				water.push_back(fy);
				water.push_back(waterZ);

				water.push_back(fx);
				water.push_back(fy + 1);
				water.push_back(waterZ);

				water.push_back(fx + 1);
				water.push_back(fy + 1);
				water.push_back(waterZ);

			}
			if (world->map[y][x].creaturesInCell.size() > 0) {
				cell = &world->map[y][x];
				for (auto creature : cell->creaturesInCell) {
					std::cout << x << " " << y << "creature x,y "
							<< creature->getId();
					creatureZ = cell->height + cell->water;

					creaturesData.push_back(fx);
					creaturesData.push_back(fy);
					creaturesData.push_back(creatureZ + heightGain);

					creaturesData.push_back(fx + 1);
					creaturesData.push_back(fy);
					creaturesData.push_back(creatureZ + heightGain);

					creaturesData.push_back(fx);
					creaturesData.push_back(fy + 1);
					creaturesData.push_back(creatureZ + heightGain);

					creaturesData.push_back(fx + 1);
					creaturesData.push_back(fy + 1);
					creaturesData.push_back(creatureZ + heightGain);

					heightGain += 0.1;

				}

			}

		}

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

	glGenVertexArrays(1, &creaturesVAO);
	glBindVertexArray(creaturesVAO);
	glGenBuffers(1, &creaturesVBO);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
	glEnableVertexAttribArray(3);
	glBindVertexArray(0);
	glGenVertexArrays(1, &waterVAO);
	glBindVertexArray(waterVAO);
	glGenBuffers(1, &waterVBO);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
	glEnableVertexAttribArray(3);
	glBindVertexArray(0);

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

}

void OpenGLWorldRenderer::prepareMapData(World *world) {
	size_t sizeData = 24 * mapHeight * mapWidth;
	std::vector<float> mapData;
	mapData.resize(24 * mapHeight * mapWidth);

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
			mapData[offset] = vertexPosX;
			mapData[offset + 1] = vertexPosY;
			mapData[offset + 2] = vertexZ;
			mapData[offset + 3] = intensity;
			getTextureCoord(vertexPosX, vertexPosY, mapData[offset + 4],
					mapData[offset + 5]);

			mapData[offset + 6] = vertexPosX;
			mapData[offset + 7] = (vertexPosY + 1.0);
			mapData[offset + 8] = vertexZ;
			mapData[offset + 9] = intensity;
			getTextureCoord(vertexPosX, vertexPosY + 1, mapData[offset + 10],
					mapData[offset + 11]);

			mapData[offset + 12] = (vertexPosX + 1.0);
			mapData[offset + 13] = vertexPosY;
			mapData[offset + 14] = vertexZ;
			mapData[offset + 15] = intensity;
			getTextureCoord((vertexPosX + 1), vertexPosY, mapData[offset + 16],
					mapData[offset + 17]);

			mapData[offset + 18] = (vertexPosX + 1.0);
			mapData[offset + 19] = (vertexPosY + 1.0);
			mapData[offset + 20] = vertexZ;
			mapData[offset + 21] = intensity;
			getTextureCoord((vertexPosX + 1), (vertexPosY + 1),
					mapData[offset + 22], mapData[offset + 23]);

		}

	}
	glGenVertexArrays(1, &mapVAO);
	glBindVertexArray(mapVAO);
	glGenBuffers(1, &mapVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mapVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mapData.size(), &mapData[0],
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
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
OpenGLWorldRenderer::OpenGLWorldRenderer(World *world) {

	this->name = "OpenGlr";
	init();
	checkOpenGLError();

	shaderProgramMap = ShadersUtils::loadShaders(
			"./shaders/vertex_shader_1.glsl",
			"./shaders/fragment_shader_1.glsl");
	shaderProgramCreature = ShadersUtils::loadShaders(
			"./shaders/vertex_shader_2.glsl",
			"./shaders/fragment_shader_2.glsl");
	shaderProgramWater = ShadersUtils::loadShaders(
			"./shaders/vertex_shader_2.glsl",
			"./shaders/fragment_shader_2_1.glsl");

	mapHeight = world->map.size();
	mapWidth = world->map[0].size();
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

		view = OpenGLControls::computeViewMatrix(window);
		mvpMatrix = projection * view * model;

		glUseProgram(shaderProgramCreature);
		mvpMatrixID = glGetUniformLocation(shaderProgramCreature, "mvpMatrix");

		prepareCreaturesData(world);
		glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, (&mvpMatrix[0][0]));

		glBindVertexArray(creaturesVAO);

		glBindBuffer(GL_ARRAY_BUFFER, creaturesVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * creaturesData.size(),
				&creaturesData[0],
				GL_STATIC_DRAW);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(3);
		for (int i = 0; i < world->creatures.size(); i++) {
			glDrawArrays(GL_TRIANGLE_STRIP, 4 * i, 4);

		}

		creaturesData.clear();

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glUseProgram(shaderProgramWater);
		mvpMatrixID = glGetUniformLocation(shaderProgramWater, "mvpMatrix");
		glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, (&mvpMatrix[0][0]));

		glBindVertexArray(waterVAO);
		glBindBuffer(GL_ARRAY_BUFFER, waterVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * water.size(), &water[0],
		GL_STATIC_DRAW);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
		glEnableVertexAttribArray(3);
		glBindBuffer(GL_ARRAY_BUFFER, waterVBO);


		for (int i = 0; i < water.size(); i += 4) {
			glDrawArrays(GL_TRIANGLE_STRIP, i, 4);

		}
		glDisableVertexAttribArray(3);
		water.clear();
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glUseProgram(shaderProgramMap);
		mvpMatrixID = glGetUniformLocation(shaderProgramMap, "mvpMatrix");

		glUniform1i(glGetUniformLocation(shaderProgramMap, "ourTexture1"), 0);
		glUniform1i(glGetUniformLocation(shaderProgramMap, "ourTexture2"), 1);

		glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, (&mvpMatrix[0][0]));

		glBindVertexArray(mapVAO);
		for (int i = 0; i < mapHeight; i++) {
			glDrawArrays(GL_TRIANGLE_STRIP, i * mapWidth * 4,
					(mapWidth - 1) * 4);
		}
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
