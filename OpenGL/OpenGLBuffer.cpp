#include "OpenGLBuffer.h"
#include <stdexcept>

OpenGLBuffer::OpenGLBuffer() {

}

OpenGLBuffer::~OpenGLBuffer() {

	glDeleteBuffers(1,&indexBufferObject);
	glDeleteBuffers(1,&vertexBufferObject);
	delete texture;
	delete bufferData;

}

void OpenGLBuffer::updateBuffer(World *world) {
	bufferData->computeBufferData(world);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, bufferData->indicesToUpate * sizeof(GLuint), &bufferData->indices[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferData->verticesToUpdate * sizeof(vertex), &bufferData->vertices[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLBuffer::initBuffer(World *world) {
	if (!bufferData) {
		throw std::runtime_error("buffer Data object isn't created");

	}

	if (!texture) {
			throw std::runtime_error("texture object is missing");

		}
	bufferData->initBufferData(world);
	texture->loadTexture();

	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &indexBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * bufferData->indices.size(), &bufferData->indices[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * bufferData->vertices.size(), &bufferData->vertices[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}
