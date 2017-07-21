#include "OpenGLWorldRenderer.h"
//#define  GL_GLEXT_PROTOTYPES
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
static GLuint shaderProgram;
static GLuint VAO, VBO;
static int numberX, numberY;

void checkOpenGLError() {
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR) {
		throw std::runtime_error("OpenGL error:\n" + std::to_string(*gluErrorString(errorCode)));
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
	std::cout<<"openGl init done";
}

void OpenGLWorldRenderer::createMatrices() {
	std::cout<<"create metrices";
	float scaleF = 1.0 / 64;
	glm::vec3 mapCenter(-0.5 * numberX, -0.5 * numberY, 0.0f);
	model = glm::scale(model, glm::vec3(scaleF, scaleF, scaleF));
	model = glm::translate(model, mapCenter);
	model = glm::rotate(model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 6.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0), 4.0 / 3, 0.1, 100.0);


}
void OpenGLWorldRenderer::bindMatrices(GLuint shaderProgram) {

	std::cout<<"bind matrices";
	mvpMatrixID = glGetUniformLocation(shaderProgram, "mvpMatrix");
	mvpMatrix = projection * view * model;

}


OpenGLWorldRenderer::OpenGLWorldRenderer(World *world) {

	this->name="OpenGlr";

	init();
	checkOpenGLError();
	shaderProgram = ShadersUtils::loadShaders("./shaders/vertex_shader_1.glsl", "./shaders/fragment_shader_1.glsl");
	std::vector<GLfloat> Points;
	numberY = world->map.size();
	numberX = world->map[0].size();


	bindMatrices(shaderProgram);

	float maxHeight = 0.0;
	float minHeight = 0.0;
	float cellHeight = 0.0;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			cellHeight = world->map[i][j].height;
			maxHeight = std::max(maxHeight, cellHeight);
			minHeight = std::min(minHeight, cellHeight);
		}
	}

	float z;
	mapDataSize = numberY * numberX * 16;
	GLfloat mapData[mapDataSize];
	//GLfloat mapColor[]

	for (int y = 0; y < numberY; y++) {
		for (int x = 0; x < numberX; x++) {
			z = world->map[y][x].height;
			GLfloat fx = x;
			GLfloat fy = y;
			GLfloat intensity = (z - minHeight) / (maxHeight - minHeight);

			mapData[16 * (x + y * numberX)] = (float) x;
			mapData[16 * (x + y * numberX) + 1] = (float) y;
			mapData[16 * (x + y * numberX) + 2] = z;

			mapData[16 * (x + y * numberX) + 3] = intensity;

			mapData[16 * (x + y * numberX) + 4] = (float) x;
			mapData[16 * (x + y * numberX) + 5] = (float) y + 1;
			mapData[16 * (x + y * numberX) + 6] = z;
			mapData[16 * (x + y * numberX) + 7] = intensity;

			mapData[16 * (x + y * numberX) + 8] = (float) x + 1;
			mapData[16 * (x + y * numberX) + 9] = (float) y;
			mapData[16 * (x + y * numberX) + 10] = z;

			mapData[16 * (x + y * numberX) + 11] = intensity;

			mapData[16 * (x + y * numberX) + 12] = (float) x + 1;
			mapData[16 * (x + y * numberX) + 13] = (float) y + 1;
			mapData[16 * (x + y * numberX) + 14] = z;

			mapData[16 * (x + y * numberX) + 15] = intensity;
		}
	}

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mapData), mapData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*) 0);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*) (3 * sizeof(GLfloat)));

	glBindVertexArray(0);

	OpenGLControls::initControls(window)  ;
	createMatrices();

}

void OpenGLWorldRenderer::work(World* world) {
	if (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		glUseProgram(shaderProgram);

		view=OpenGLControls::computeViewMatrix(window);
		mvpMatrix = projection * view * model;

		glUniformMatrix4fv(mvpMatrixID, 1, GL_FALSE, (&mvpMatrix[0][0]));

		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		for (int i = 0; i < numberX * numberY * 4; i += 4) {
			glDrawArrays(GL_TRIANGLE_STRIP, i, 4);

		}

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

}
OpenGLWorldRenderer::~OpenGLWorldRenderer(){

}

