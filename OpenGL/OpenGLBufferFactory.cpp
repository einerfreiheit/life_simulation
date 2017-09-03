#include "OpenGLBufferFactory.h"
#include "OpenGLBufferMap.h"
#include "OpenGLBufferCreatures.h"
#include  "OpenGlBufferWater.h"

void OpenGLBufferFactory::buildBuffers(	std::vector<OpenGLBuffer*> &staticBuffers,
										std::vector<OpenGLBuffer*> &dynamicBuffers) {
	addBuffer<OpenGLBufferMap>(staticBuffers, dynamicBuffers, "./textures/ground _1.jpg");
	addBuffer<OpenGlBufferWater>(staticBuffers, dynamicBuffers, "./textures/water.jpg");
	addBuffer<OpenGLBufferCreatures>(staticBuffers, dynamicBuffers, "./textures/worm.jpg");
}
