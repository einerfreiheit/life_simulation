#ifndef OPENGL_OPENGLBUFFERFACTORY_H_
#define OPENGL_OPENGLBUFFERFACTORY_H_

#include <vector>

#include "OpenGLBuffer.h"
#include "OpenGLBufferData.h"
#include "OpenGLTexture.h"

class OpenGLBufferFactory {
public:

	template<typename T> static void addBuffer(	std::vector<OpenGLBuffer*> &staticBuffers,
												std::vector<OpenGLBuffer*> &dynamicBuffers,
												const std::string &texturePath) {
		OpenGLBuffer *buffer = new OpenGLBuffer;
		OpenGLBufferData *bufferData = new T;
		buffer->bufferData = bufferData;
		if (bufferData->type == BT_STATIC) {
			staticBuffers.push_back(buffer);
		}
		else {
			dynamicBuffers.push_back(buffer);
		}
		buffer->texture = new OpenGLTexture(GL_TEXTURE_2D, texturePath);
	}

	static void buildBuffers(std::vector<OpenGLBuffer*> &staticBuffers, std::vector<OpenGLBuffer*> &dynamicBuffers);

};

#endif
