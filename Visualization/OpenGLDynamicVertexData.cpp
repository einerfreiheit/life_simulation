#include "OpenGLDynamicVertexData.h"
#include <iostream>
OpenGLDynamicVertexData::OpenGLDynamicVertexData() {
}


void OpenGLDynamicVertexData::updateBuffers(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * vertexIndices.size(), &vertexIndices[0], GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferSubData(GL_ARRAY_BUFFER, 0, verticesToUpdate * sizeof(vertex), &vertices[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
void OpenGLDynamicVertexData::update(World *world){

	computeBuffersData(world);
	updateBuffers();
	elementNumber = vertexIndices.size();
	vertexIndices.clear();
}
