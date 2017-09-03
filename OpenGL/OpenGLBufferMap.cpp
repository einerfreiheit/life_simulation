#include "OpenGLBufferMap.h"

OpenGLBufferMap::OpenGLBufferMap() {
	type = BT_STATIC;

}

OpenGLBufferMap::~OpenGLBufferMap() {

}

void OpenGLBufferMap::initBufferData(World *world) {
	vertices.resize(world->map[0].size() * world->map.size() * 20);
	indices.resize(world->map[0].size() * world->map.size() * 6);
	objectTextureSize = 1 / 128.0;

}

void OpenGLBufferMap::computeBufferData(World *world) {
	indicesToUpate=0;
	verticesToUpdate=0;
	float vertexZ;

	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			vertexZ = world->map[y][x].height;
			addCellVertices(world->getCell(y, x), vertexZ);
		}
	}

}
