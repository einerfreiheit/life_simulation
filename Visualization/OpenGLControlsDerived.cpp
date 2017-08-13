#include "OpenGLControlsDerived.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

OpenGLControlsDerived::OpenGLControlsDerived() {
	initialize();

}

glm::mat4 OpenGLControlsDerived::getViewMatrix() {
	view = glm::lookAt(	cameraPosition,
						glm::vec3(cameraPosition.x, cameraPosition.y, 0.0f),
						glm::vec3(0.0f, 1.0f, 0.0f));

	view = glm::rotate(view, rotationAngles.x, glm::vec3(-1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, rotationAngles.y, glm::vec3(0.0f, -1.0f, 0.0f));
	return view;

}
void OpenGLControlsDerived::keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) {
	onKeys(key, action);

}

void OpenGLControlsDerived::cursorCallBack(GLFWwindow *window, double xPos, double yPos) {

	float deltaXpos = lastMouseX - xPos;
	float deltaYpos = lastMouseY - yPos;
	rotationAngles.x += glm::atan(deltaYpos, cameraPosition.z) * cameraRotationSpeed;
	rotationAngles.y += glm::atan(deltaXpos, cameraPosition.z) * cameraRotationSpeed;
	lastMouseX = xPos;
	lastMouseY = yPos;
}

void OpenGLControlsDerived::initialize() {
	cameraPosition = glm::vec3(0.0f, 0.0f, 6.5f);
	view = glm::lookAt(	cameraPosition,
						glm::vec3(cameraPosition.x, cameraPosition.y, 0.0f),
						glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, rotationAngles.x, glm::vec3(-1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, rotationAngles.y, glm::vec3(0.0f, -1.0f, 0.0f));
	lastMouseX = initialX;
	lastMouseY = initialY;

}
void OpenGLControlsDerived::onKeys(int key, int action) {
	if (action != GLFW_PRESS) {
		return;
	}
	switch (key) {
	case GLFW_KEY_UP: {
		cameraPosition.y += cameraMoveSpeed;
	}
		break;
	case GLFW_KEY_DOWN: {
		cameraPosition.y -= cameraMoveSpeed;
	}
		break;
	case GLFW_KEY_LEFT: {
		cameraPosition.x -= cameraMoveSpeed;
	}
		break;
	case GLFW_KEY_RIGHT: {
		cameraPosition.x += cameraMoveSpeed;
	}
		break;
	case GLFW_KEY_W: {
		cameraPosition.z += cameraMoveSpeed;
	}
		break;
	case GLFW_KEY_S: {
		cameraPosition.z -= cameraMoveSpeed;
	}
		break;
	default: {
	}
	}

}

OpenGLControlsDerived::~OpenGLControlsDerived() {

}

