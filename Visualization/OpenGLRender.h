#ifndef VISUALIZATION_OPENGLRENDER_H_
#define VISUALIZATION_OPENGLRENDER_H_

#include "../World.h"
#include <GL/glew.h>
#include <glm/matrix.hpp>

#include "OpenGLCamera.h"


#include "OpenGLWaterData.h"
#include "OpenGLMapData.h"
#include "OpenGLCreaturesData.h"


class OpenGLRender {
public:
	OpenGLRender(World *world);
	virtual ~OpenGLRender();
	void draw(World *world);
	static void init();

private:
	static void checkError();
	static GLFWwindow *window;
	GLuint shader;
	GLuint vertexAttributeObject;
	GLuint shaderMVP;
	GLuint shaderTexture;
	glm::mat4 mvpMatrix;


	OpenGLCamera *camera=NULL;
	OpenGLMapData * mapData=NULL;
	OpenGLWaterData *waterData=NULL;
	OpenGLCreaturesData *creatureData =NULL;






};

#endif
