#ifndef VISUALIZATION_OPENGLWATERDATA_H_
#define VISUALIZATION_OPENGLWATERDATA_H_


#include "OpenGLDynamicVertexData.h"

class OpenGLWaterData  : public OpenGLDynamicVertexData{
public:
	OpenGLWaterData();
	void computeBuffersData(World *world) override;
	void initBuffers(World *world) override;

};

#endif
