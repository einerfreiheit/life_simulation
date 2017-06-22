#include "OpenGLWorldRenderer.h"
//#define GLEW_STATIC
//#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <exception>

static GLFWwindow* window;

OpenGLWorldRenderer::OpenGLWorldRenderer() {
	//glutCreateWindow("GLEW Test");

	if (glfwInit() != GL_TRUE) {
		throw std::runtime_error("GLFW init failed");
	}
	/*glewExperimental=true;
	 GLenum err = glewInit();
	 if (GLEW_OK != err)
	 {
	 throw std::runtime_error("GLEW initialization failed: " + std::string((char *)glewGetErrorString(err)));
	 }
	 printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	 */
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
}

void OpenGLWorldRenderer::work(World* world) {
	glfwPollEvents();

	glfwSwapBuffers(window);
}
