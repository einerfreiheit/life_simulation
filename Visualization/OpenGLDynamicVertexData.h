#ifndef VISUALIZATION_OPENGLDYNAMICVERTEXDATA_H_
#define VISUALIZATION_OPENGLDYNAMICVERTEXDATA_H_

#include "OpenGLVertexData.h"

class OpenGLDynamicVertexData  : public OpenGLVertexData{
public:
	OpenGLDynamicVertexData();
	GLuint verticesToUpdate;
	virtual void updateBuffers();
	void update(World *world) override;
	virtual void initBuffers(World *world) =0;

};

#endif
