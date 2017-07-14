#ifndef OPENGLWORLDRENDERER_H
#define OPENGLWORLDRENDERER_H

#include <WorldWorker.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>


class OpenGLWorldRenderer: public WorldWorker {
public:
	OpenGLWorldRenderer(World *world);

	virtual void work(World* world);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	void prepareMapData(World *world);
	GLuint  bindData(const std::vector <float> & vertices);
	void bindMatrices(GLuint shaderProgram);

private:
	std::vector <float> mapVerices;
	std::vector <float> mapCenter{2};
	GLuint mapVAO;

};

#endif // OPENGLWORLDRENDERER_H
