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
static GLuint VAO, VBO, EBO, colorVBO;
static float alfa = 0.0f;
;
static int numberX, numberY;

void checkOpenGLError() {
	GLenum errorCode = glGetError();
	if (errorCode != GL_NO_ERROR) {
		throw std::runtime_error("OpenGL error:\n" + std::to_string(*gluErrorString(errorCode)));
	}
}

void init() {
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

}



OpenGLWorldRenderer::OpenGLWorldRenderer(World *world) {

	init();
	checkOpenGLError();
	shaderProgram = ShadersUtils::loadShaders("./shaders/vertex_shader_1.glsl", "./shaders/fragment_shader_1.glsl");
	std::vector<GLfloat> Points;
	numberY = world->map.size();
	numberX = world->map[0].size();
	float num = world->map[0].size();
	float z;
	for (int y = 0; y < numberY; y++) {
		for (int x = 0; x < numberX; x++) {
			z = world->map[y][x].height;

			Points.push_back((float) x);
			Points.push_back((float) -y);
			Points.push_back(z);

			Points.push_back((float) x);
			Points.push_back((float) -y - 1);
			Points.push_back(z);

			Points.push_back((float) x + 1);
			Points.push_back((float) -y);
			Points.push_back(z);

			Points.push_back((float) x + 1);
			Points.push_back((float) -y - 1);
			Points.push_back(z);
		}
	}

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Points.size() * sizeof(Points), Points.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(GLfloat), (GLvoid*) 0);

	glDisableVertexAttribArray(0);
	glBindVertexArray(0);

}

void OpenGLWorldRenderer::work(World* world) {
	alfa += 0.1f;
	if (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);

		float scaleF = 1.0 / 128;

		glm::vec3 mapCenter(-0.5 * numberX, 0.5 * numberY, 0.0f);

		glm::mat4 modelMatrix(1.0f);

		modelMatrix = glm::scale(modelMatrix, glm::vec3(scaleF, scaleF, scaleF)); // перенести в билдер матриц
		modelMatrix = glm::translate(modelMatrix, mapCenter);
		modelMatrix = glm::rotate(modelMatrix, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(shaderProgram, "modelMatrix");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));

		glm::mat4 view(1.0f);
		view = glm::lookAt(glm::vec3(0.0f, 1.0f, -3.2f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 projection(1.0f);
		projection = glm::perspective(glm::radians(45.0), 4.0 / 3, 0.1, 100.0);

		GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		GLint projectionLoc = glGetUniformLocation(shaderProgram, "projection");
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		for (int i = 0; i <= numberX * numberY * 4; i += 4) {
			glDrawArrays(GL_TRIANGLE_STRIP, i, 4);

		}

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

}

