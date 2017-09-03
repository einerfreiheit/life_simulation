#include "OpenGLBufferData.h"

OpenGLBufferData::OpenGLBufferData() {

}

OpenGLBufferData::~OpenGLBufferData() {

}

void OpenGLBufferData::addCellVertices(Cell*cell, float&vertexZ) {

	float fx = cell->xCoordinate;
	float fy = cell->yCoordinate;

	indices[indicesToUpate] = verticesToUpdate + 1;
	indices[indicesToUpate + 1] = verticesToUpdate + 2;
	indices[indicesToUpate + 2] = verticesToUpdate;
	indices[indicesToUpate + 3] = verticesToUpdate + 1;
	indices[indicesToUpate + 4] = verticesToUpdate + 2;
	indices[indicesToUpate + 5] = verticesToUpdate + 3;
	indicesToUpate += 6;

	vertices[verticesToUpdate].vertexPosition[0] = fx;
	vertices[verticesToUpdate].vertexPosition[1] = fy;
	vertices[verticesToUpdate].vertexPosition[2] = vertexZ;
	vertices[verticesToUpdate].textureUV[0] = fx * objectTextureSize;
	vertices[verticesToUpdate].textureUV[1] = fy * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].vertexPosition[0] = fx + 1;
	vertices[verticesToUpdate].vertexPosition[1] = fy;
	vertices[verticesToUpdate].vertexPosition[2] = vertexZ;
	vertices[verticesToUpdate].textureUV[0] = (fx + 1) * objectTextureSize;
	vertices[verticesToUpdate].textureUV[1] = fy * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].vertexPosition[0] = fx;
	vertices[verticesToUpdate].vertexPosition[1] = fy + 1;
	vertices[verticesToUpdate].vertexPosition[2] = vertexZ;
	vertices[verticesToUpdate].textureUV[0] = fx * objectTextureSize;
	vertices[verticesToUpdate].textureUV[1] = (fy + 1) * objectTextureSize;
	verticesToUpdate++;

	vertices[verticesToUpdate].vertexPosition[0] = fx + 1;
	vertices[verticesToUpdate].vertexPosition[1] = fy + 1;
	vertices[verticesToUpdate].vertexPosition[2] = vertexZ;
	vertices[verticesToUpdate].textureUV[0] = (fx + 1) * objectTextureSize;
	vertices[verticesToUpdate].textureUV[1] = (fy + 1) * objectTextureSize;
	verticesToUpdate++;

}
