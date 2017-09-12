#include "OpenGLBufferData.h"

OpenGLBufferData::OpenGLBufferData() {

}

OpenGLBufferData::~OpenGLBufferData() {

}

void OpenGLBufferData::addCellVertices(Cell*cell, float&vertexZ) {

	float fx = cell->x;
	float fy = cell->y;

	indices[indicesToUpate] = verticesToUpdate + 1;
	indices[indicesToUpate + 1] = verticesToUpdate + 2;
	indices[indicesToUpate + 2] = verticesToUpdate;
	indices[indicesToUpate + 3] = verticesToUpdate + 1;
	indices[indicesToUpate + 4] = verticesToUpdate + 2;
	indices[indicesToUpate + 5] = verticesToUpdate + 3;
	indicesToUpate += 6;

	vertices[verticesToUpdate].x = fx;
	vertices[verticesToUpdate].y = fy;
	vertices[verticesToUpdate].z = vertexZ;
	vertices[verticesToUpdate].textureX = fx * objectTextureSize;
	vertices[verticesToUpdate].textureY = fy * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx + 1;
	vertices[verticesToUpdate].y = fy;
	vertices[verticesToUpdate].z = vertexZ;
	vertices[verticesToUpdate].textureX = (fx + 1) * objectTextureSize;
	vertices[verticesToUpdate].textureY = fy * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx;
	vertices[verticesToUpdate].y = fy + 1;
	vertices[verticesToUpdate].z = vertexZ;
	vertices[verticesToUpdate].textureX = fx * objectTextureSize;
	vertices[verticesToUpdate].textureY = (fy + 1) * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx + 1;
	vertices[verticesToUpdate].y = fy + 1;
	vertices[verticesToUpdate].z = vertexZ;
	vertices[verticesToUpdate].textureX = (fx + 1) * objectTextureSize;
	vertices[verticesToUpdate].textureY = (fy + 1) * objectTextureSize;
	verticesToUpdate++;

}

void OpenGLBufferData::addCellVertices(Cell *cell) {

	float fx = cell->x;
	float fy = cell->y;


	indices[indicesToUpate] = verticesToUpdate + 1;
	indices[indicesToUpate + 1] = verticesToUpdate + 2;
	indices[indicesToUpate + 2] = verticesToUpdate;
	indices[indicesToUpate + 3] = verticesToUpdate + 1;
	indices[indicesToUpate + 4] = verticesToUpdate + 2;
	indices[indicesToUpate + 5] = verticesToUpdate + 3;
	indicesToUpate += 6;

	vertices[verticesToUpdate].x = fx;
	vertices[verticesToUpdate].y = fy;
	vertices[verticesToUpdate].z = cell->heights[0][0];
	vertices[verticesToUpdate].textureX = fx * objectTextureSize;
	vertices[verticesToUpdate].textureY = fy * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx + 1;
	vertices[verticesToUpdate].y = fy;
	vertices[verticesToUpdate].z = cell->heights[0][1];
	vertices[verticesToUpdate].textureX = (fx + 1) * objectTextureSize;
	vertices[verticesToUpdate].textureY = fy * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx;
	vertices[verticesToUpdate].y = fy + 1;
	vertices[verticesToUpdate].z = cell->heights[1][0];
	vertices[verticesToUpdate].textureX = fx * objectTextureSize;
	vertices[verticesToUpdate].textureY = (fy + 1) * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx + 1;
	vertices[verticesToUpdate].y = fy + 1;
	vertices[verticesToUpdate].z = cell->heights[1][1];
	vertices[verticesToUpdate].textureX = (fx + 1) * objectTextureSize;
	vertices[verticesToUpdate].textureY = (fy + 1) * objectTextureSize;
	verticesToUpdate++;
}

