#include "../OpenGL/OpenGLCamera.h"

#include <iostream>
OpenGLCamera* OpenGLCamera::instance = NULL;

OpenGLCamera::OpenGLCamera(GLFWwindow *window) {
	instance = this;
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwGetCursorPos(window, &lastMouseX, &lastMouseY);
	cameraPosition = glm::vec3(0.0f, 0.0f, 6.5f);
	float scaleF = 1.0 / 64;


	std::cout<<height<<" height"<<width<<"width";
	glm::vec3 mapCenter(-0.5 * SimulationData::getInst()->mapWidth, -0.5 * SimulationData::getInst()->mapHeight, 0.0f);
	model = glm::scale(model, glm::vec3(scaleF, scaleF, scaleF));
	model = glm::translate(model, mapCenter);
	model = glm::rotate(model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::lookAt(glm::vec3(0.0f, 0.0f, 6.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0), 4.0 / 3, 0.1, 100.0);

	mvp = projection*view*model;

}

glm::mat4 OpenGLCamera::getMVPMatrix() {
	view = glm::lookAt(	cameraPosition,
						glm::vec3(cameraPosition.x, cameraPosition.y, 0.0f),
						glm::vec3(0.0f, 1.0f, 0.0f));

	view = glm::rotate(view, rotationAngles.x, glm::vec3(-1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, rotationAngles.y, glm::vec3(0.0f, -1.0f, 0.0f));



	mvp = projection*view*model;
	return mvp;

}
OpenGLCamera::~OpenGLCamera() {
}

void OpenGLCamera::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (instance) {
		instance->updateKeys(window, key, scancode, action, mods);
	}
}

void OpenGLCamera::cursorCallBack(GLFWwindow*window, double xPos, double yPos) {
	if (instance) {
		instance->updateCursor(window, xPos, yPos);
	}
}

void OpenGLCamera::updateCursor(GLFWwindow*window, double xPos, double yPos) {
	float deltaXpos = lastMouseX - xPos;
	float deltaYpos = lastMouseY - yPos;
	rotationAngles.x += glm::atan(deltaYpos, cameraPosition.z) * cameraRotationSpeed;
	rotationAngles.y += glm::atan(deltaXpos, cameraPosition.z) * cameraRotationSpeed;
	lastMouseX = xPos;
	lastMouseY = yPos;

}

void OpenGLCamera::updateKeys(GLFWwindow *window, int key, int scancode, int action, int mods) {
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
		break;
	}

}
