#ifndef OPENGL_OPENGLBUFFERMAP_H_
#define OPENGL_OPENGLBUFFERMAP_H_

#include "OpenGLBufferData.h"

class OpenGLBufferMap: public OpenGLBufferData {
public:
	OpenGLBufferMap();
	~OpenGLBufferMap();
	void initBufferData(World *world);
	void computeBufferData(World *world);
	void getHeightDepth(World *world, float &minHeight, float &maxHeight);

};

#endif
