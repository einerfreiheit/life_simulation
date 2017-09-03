#ifndef OPENGL_OPENGLBUFFER_H_
#define OPENGL_OPENGLBUFFER_H_

#include "OpenGLBufferData.h"
#include "../Visualization/OpenGLTexture.h"
#include "../World.h"

class OpenGLBuffer {
public:
	OpenGLBuffer();
	virtual ~OpenGLBuffer();
	OpenGLBufferData *bufferData = NULL;
	OpenGLTexture *texture = NULL;

	void initBuffer(World *world);
	void updateBuffer(World *world);

	GLuint vertexBufferObject;
	GLuint indexBufferObject;


};

#endif
