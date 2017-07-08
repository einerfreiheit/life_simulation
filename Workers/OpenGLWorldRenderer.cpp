#include "OpenGLWorldRenderer.h"
//#define  GL_GLEXT_PROTOTYPES
#define GLEW_STATIC
#include <glm/glm.hpp>
#include <stdio.h>
#include <exception>
#include <string>
#include <iostream>
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
void initShaders() {
	GLint success;
	GLchar infolog[512];

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
		throw std::runtime_error("vertexShader compile error:\n" + std::to_string(*infolog));
	}
	std::cout << "vertex shader is ok\n";

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
		throw std::runtime_error("fragmentShader compile error:\n" + std::to_string(*infolog));
	}
	std::cout << "fragment shader is ok\n";

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		throw std::runtime_error("shader program link error:\n" + std::to_string(*infolog));
	}
	std::cout << " shader program is ok\n";
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

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


OpenGLWorldRenderer::OpenGLWorldRenderer() {


	init();
	checkOpenGLError();
	initShaders();


	GLfloat vertices[] = { -0.5f,-0.5f,0.0f,
	0.0f,0.5f,0.0f,
	0.5f,-0.5f,0.0f,
	0.0f,0.0f,1.0f
	};
	GLfloat colors[] = { 1.0f, 0.5f, 0.2f, 1.0f,
			1.0f, 0.5f, 0.2f, 1.0f,
			1.0f, 0.5f, 0.2f, 1.0f,
			1.0f, 0.5f, 0.2f, 1.0f

	};
	GLuint indices[] = { 0, 1, 2, 0,1,3,1,2,3,0,2,3};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) 0);

	glGenBuffers(1, &colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);


	glBindVertexArray(0);

}

void OpenGLWorldRenderer::work(World* world) {
	if (!glfwWindowShouldClose(window)) {
		glfwPollEvents();


		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

}

