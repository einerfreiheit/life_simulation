#ifndef VISUALIZATION_OPENGLCONTROLSBASE_H_
#define VISUALIZATION_OPENGLCONTROLSBASE_H_

#include <GLFW/glfw3.h>
class OpenGLControlsBase {
public:

	virtual void keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;
	virtual void cursorCallBack(GLFWwindow*window, double xPos, double yPos)=0;
	static OpenGLControlsBase * controlsInstance;
	virtual void setInstancePointer() {
		controlsInstance = this;
	}

	static void keyCallBackDispatch(GLFWwindow *window, int key, int scancode, int action, int mods) {
		if (controlsInstance) {
			controlsInstance->keyCallBack(window, key, scancode, action, mods);

		}
	}

	static void cursorCallBackDispatch(GLFWwindow*window, double xPos, double yPos) {
		if (controlsInstance) {
			controlsInstance->cursorCallBack(window, xPos,yPos);

		}
	}

	static void init(GLFWwindow *window);
	static double initialX;
	static double initialY;

};

#endif
