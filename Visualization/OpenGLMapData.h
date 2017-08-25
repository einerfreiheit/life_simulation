#ifndef VISUALIZATION_OPENGLMAPDATA_H_
#define VISUALIZATION_OPENGLMAPDATA_H_
#include "OpenGLVertexData.h"

class OpenGLMapData: public OpenGLVertexData {
public:
	OpenGLMapData();

	GLsizei elementNumber;
	void computeData(World *world);

private:
	void computeVertexData(World *world);
	void updateBuffers();
	void getHeightDepth(World *world);
	float minHeight;
	float maxHeight;
};

#endif
