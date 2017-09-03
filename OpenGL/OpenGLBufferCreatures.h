#ifndef OPENGL_OPENGLBUFFERCREATURES_H_
#define OPENGL_OPENGLBUFFERCREATURES_H_

#include "OpenGLBufferData.h"

class OpenGLBufferCreatures: public OpenGLBufferData {
public:
	OpenGLBufferCreatures();
	virtual ~OpenGLBufferCreatures();
	void initBufferData(World *world);
	void computeBufferData(World *world);

};

#endif
