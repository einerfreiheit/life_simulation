#include "OpenGLVertexData.h"
OpenGLVertexData::OpenGLVertexData() {
	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &indexBufferObject);
}

OpenGLVertexData::~OpenGLVertexData() {
	glDeleteBuffers(1, &vertexBufferObject);
	glDeleteBuffers(1, &indexBufferObject);

}


void OpenGLVertexData::update(World *world) {
	computeBuffersData(world);
//	updateBuffers();
	elementNumber = vertexIndices.size();
	vertexIndices.clear();

}
