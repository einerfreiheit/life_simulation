#ifndef OPENGLWORLDRENDERER_H
#define OPENGLWORLDRENDERER_H

#include <WorldWorker.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class OpenGLWorldRenderer: public WorldWorker {
public:
	OpenGLWorldRenderer();

	virtual void work(World* world);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


};

#endif // OPENGLWORLDRENDERER_H
