#include "OpenGlBufferWater.h"

OpenGlBufferWater::OpenGlBufferWater() {
	type = BT_DYNAMIC;

}

OpenGlBufferWater::~OpenGlBufferWater() {
}

void OpenGlBufferWater::initBufferData(World *world) {
	vertices.resize(world->map[0].size() * world->map.size() * 20);
	indices.resize(world->map[0].size() * world->map.size() * 6);
	objectTextureSize = 1 / 128.0;

}

void OpenGlBufferWater::computeBufferData(World *world) {

	indicesToUpate = 0;
	verticesToUpdate = 0;
	float vertexZ;
	Cell *cell = NULL;

	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			cell = world->getCell(y, x);
			if (cell->water > 0.1) {
				vertexZ = cell->height + cell->water;
				addCellVertices(world->getCell(y, x), vertexZ);

			}

		}
	}

}
