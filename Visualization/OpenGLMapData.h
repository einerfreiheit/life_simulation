#ifndef VISUALIZATION_OPENGLMAPDATA_H_
#define VISUALIZATION_OPENGLMAPDATA_H_
#include "OpenGLVertexData.h"

class OpenGLMapData: public OpenGLVertexData {
public:
	OpenGLMapData();


	void computeBuffersData(World *world);

private:
	void getHeightDepth(World *world);
	float minHeight;
	float maxHeight;
};

#endif
