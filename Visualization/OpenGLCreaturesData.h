#ifndef VISUALIZATION_OPENGLCREATURESDATA_H_
#define VISUALIZATION_OPENGLCREATURESDATA_H_

#include "OpenGLDynamicVertexData.h"

class OpenGLCreaturesData: public OpenGLDynamicVertexData {
public:
	OpenGLCreaturesData();
	void computeBuffersData(World *world) override;
	void initBuffers(World *world) override;
};

#endif
