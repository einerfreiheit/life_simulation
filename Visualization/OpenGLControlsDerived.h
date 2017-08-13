#ifndef VISUALIZATION_OPENGLCONTROLSDERIVED_H_
#define VISUALIZATION_OPENGLCONTROLSDERIVED_H_

#include "OpenGLControlsBase.h"
#include <glm/glm.hpp>


class OpenGLControlsDerived  : public OpenGLControlsBase{
public:
	OpenGLControlsDerived();
	virtual ~OpenGLControlsDerived();
	virtual void  keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods);
	virtual void cursorCallBack(GLFWwindow *window, double xPos,double yPos);
	glm::mat4 view ;
	glm::mat4 getViewMatrix();

private:


	void initialize();
	bool shouldUpdate;
	void onMouse(GLFWwindow *window);
	void onKeys(int key, int action);
	const float cameraMoveSpeed =0.01;
	const float cameraRotationSpeed =0.01;
	glm::vec3 cameraPosition;

	double currentMouseX;
	double currentMouseY;
	double lastMouseX;
	double lastMouseY;

	glm::vec2 rotationAngles;



};

#endif
