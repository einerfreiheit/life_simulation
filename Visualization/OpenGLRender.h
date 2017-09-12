#ifndef VISUALIZATION_OPENGLRENDER_H_
#define VISUALIZATION_OPENGLRENDER_H_

#include "../World.h"
#include <GL/glew.h>
#include <glm/matrix.hpp>
#include "OpenGLCamera.h"
#include "../OpenGL/OpenGLBuffer.h"



class OpenGLRender {
public:
	OpenGLRender(World *world);
	virtual ~OpenGLRender();
	void draw(World *world);
	static void init();

private:
	std::vector <OpenGLBuffer*> staticBuffers;
	std::vector <OpenGLBuffer*> dynamicBuffers;
	static void checkError();
	static GLFWwindow *window;
	GLuint shader;
	GLuint vertexAttributeObject;
	GLuint shaderMVP;
	GLuint shaderTexture;
	glm::mat4 mvpMatrix;
	OpenGLCamera *camera=NULL;

};

#endif
