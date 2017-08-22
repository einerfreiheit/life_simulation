#ifndef VISUALIZATION_OPENGLCAMERA_H_
#define VISUALIZATION_OPENGLCAMERA_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "../SimulationData.h"

class OpenGLCamera {
public:
	OpenGLCamera(GLFWwindow *window);
	virtual ~OpenGLCamera();
	static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void cursorCallBack(GLFWwindow*window, double xPos, double yPos);
	glm::mat4 getMVPMatrix();
private:
	void updateCursor(GLFWwindow*window, double xPos, double yPos);
	void updateKeys(GLFWwindow *window, int key, int scancode, int action, int mods);
	static OpenGLCamera *instance;
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 projection;
	glm::mat4 mvp;

	const float cameraMoveSpeed = 0.1;
	const float cameraRotationSpeed = 0.01;
	glm::vec3 cameraPosition;
	double lastMouseX;
	double lastMouseY;
	glm::vec2 rotationAngles;

};

#endif
