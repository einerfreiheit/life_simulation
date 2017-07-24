#ifndef VISUALIZATION_OPENGLCONTROLS_H_
#define VISUALIZATION_OPENGLCONTROLS_H_
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

enum KEY_TYPE{unkown=0,up=GLFW_KEY_UP,down=GLFW_KEY_DOWN,left=GLFW_KEY_LEFT, right = GLFW_KEY_RIGHT};
class OpenGLControls {
public:

	static glm::mat4 computeViewMatrix(GLFWwindow *window);
	static void initControls(GLFWwindow *window);
	static double cursorLastX;
	static double cursorLastY;
	static double cursorCurrentX;
	static double cursorCurrentY;
	static float deltaX ;
	static float deltaY ;
	static int height;
	static int width ;
	static float moveSpeed;
	static float mouseSpeed ;
	static float rotationXangle;
	static float rotationYangle;


};

#endif
