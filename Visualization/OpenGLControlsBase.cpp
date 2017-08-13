#include "OpenGLControlsBase.h"
#include <iostream>
OpenGLControlsBase * OpenGLControlsBase::controlsInstance;
double OpenGLControlsBase::initialX=0.0;
double OpenGLControlsBase::initialY=0.0;
void OpenGLControlsBase::init(GLFWwindow *window) {

	int width, height;
	glfwGetWindowSize(window, &width, &height);
	glfwSetCursorPos(window, width / 2, height / 2);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwGetCursorPos(window, &initialX,&initialY);


}
