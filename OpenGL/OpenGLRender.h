#ifndef OPENGL_OPENGLRENDER_H_
#define OPENGL_OPENGLRENDER_H_

#include "../World.h"
#include <GL/glew.h>
#include <glm/matrix.hpp>
#include "../OpenGL/OpenGLBuffer.h"
#include "../OpenGL/OpenGLCamera.h"



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
