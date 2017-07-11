#include "OpenGLWorldRenderer.h"
//#define  GL_GLEXT_PROTOTYPES
#define GLEW_STATIC
#include <glm/glm.hpp>
#include <stdio.h>
#include <exception>
#include <string>
#include <iostream>
#include <vector>

#include "../Visualization/ShadersUtils.h"

static GLFWwindow* window = NULL;
static GLuint shaderProgram;
static GLuint VAO, VBO, EBO, colorVBO;

const GLchar* vertexShaderSource = "# version 330 core\n"
		"layout(location=0) in vec3 position;\n"
		"layout(location=1)in vec4 vertexColor;"
		"out vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4 (position.x,position.y,position.z,1.0);\n"
		"ourColor = vertexColor;\n"
		"}\n";
const GLchar* fragmentShaderSource = "#version 330 core\n"
		"in vec4 ourColor;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = ourColor;\n"
		"}\n";

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
	std::vector<GLfloat> vertices = {
	        -0.4f, 0.6f,
	        0.4f, 0.6f,
	        0.6f, 0.4f,
	        0.6f, -0.4f,
	        0.4f, -0.6f,
	        -0.4f, -0.6f,
	};
	std::vector<GLfloat> Points;
	 for (int y = 0; y < world->map.size(); y++) {
	 for (int x = 0; x < world->map[0].size(); x++) {
	 Points.push_back(x);
	 Points.push_back(y);
	 Points.push_back(world->map[y][x].height);


	 }

	 }


	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*) 0);

	glDisableVertexAttribArray(0);
	glBindVertexArray(0);

}

void OpenGLWorldRenderer::work(World* world) {
	if (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, 6);

		glDisableVertexAttribArray(0);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

}

