#include "OpenGLControls.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

glm::vec3 position = glm::vec3(0.0f, 0.0f, 6.5f);

double OpenGLControls::cursorCurrentX = 0.0;
double OpenGLControls::cursorCurrentY = 0.0;
double OpenGLControls::cursorLastX = 0.0;
double OpenGLControls::cursorLastY = 0.0;
float OpenGLControls::deltaX = 0.0;
float OpenGLControls::deltaY = 0.0;
int OpenGLControls::height = 0;
int OpenGLControls::width = 0;
float OpenGLControls::mouseSpeed = 0.1;
float OpenGLControls::moveSpeed = 0.1;
float OpenGLControls::rotationXangle = 0.0;
float OpenGLControls::rotationYangle = 0.0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		position.y += OpenGLControls::moveSpeed;
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		position.y -= OpenGLControls::moveSpeed;
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		position.x -= OpenGLControls::moveSpeed;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		position.x += OpenGLControls::moveSpeed;
	}
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		position.z += OpenGLControls::moveSpeed;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		position.z -= OpenGLControls::moveSpeed;
	}

}

void OpenGLControls::initControls(GLFWwindow *window) {
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);
	glfwGetCursorPos(window, &cursorLastX, &cursorLastY);
	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window,GLFW_STICKY_KEYS,GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

}

glm::mat4 OpenGLControls::computeViewMatrix(GLFWwindow *window) {

	glfwGetCursorPos(window, &cursorCurrentX, &cursorCurrentY);

	deltaX = cursorLastX - cursorCurrentX;
	deltaY = cursorLastY - cursorCurrentY;

	rotationXangle += glm::atan(deltaY, position.z) * mouseSpeed;
	rotationYangle += glm::atan(deltaX, position.z) * mouseSpeed;
	glm::mat4 view = glm::lookAt(position, glm::vec3(position.x, position.y, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, rotationXangle, glm::vec3(-1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, rotationYangle, glm::vec3(0.0f, -1.0f, 0.0f));
	cursorLastX = cursorCurrentX;
	cursorLastY = cursorCurrentY;
	return view;
}

