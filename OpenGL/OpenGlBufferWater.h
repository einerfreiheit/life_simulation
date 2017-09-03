#ifndef OPENGL_OPENGLBUFFERWATER_H_
#define OPENGL_OPENGLBUFFERWATER_H_

#include "OpenGLBufferData.h"

class OpenGlBufferWater: public OpenGLBufferData {
public:
	OpenGlBufferWater();
	virtual ~OpenGlBufferWater();

	void initBufferData(World *world);
	void computeBufferData(World *world);
};

#endif
