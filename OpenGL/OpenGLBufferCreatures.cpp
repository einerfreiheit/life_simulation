#include "OpenGLBufferCreatures.h"

OpenGLBufferCreatures::OpenGLBufferCreatures() {
	type = BT_DYNAMIC;

}

OpenGLBufferCreatures::~OpenGLBufferCreatures() {

}

void OpenGLBufferCreatures::initBufferData(World *world) {
	vertices.resize(world->map[0].size() * world->map.size() * 20);
	indices.resize(world->map[0].size() * world->map.size() * 6);
	objectTextureSize = 1.0;

}

void OpenGLBufferCreatures::computeBufferData(World *world) {
	indicesToUpate = 0;
	verticesToUpdate = 0;
	float vertexZ;
	float heightOffset = 0.1;
	Cell *cell = NULL;

	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			cell = world->getCell(y, x);
			if (!cell->creaturesInCell.empty()) {
				for (auto creature : cell->creaturesInCell) {
					vertexZ = cell->height + cell->water + heightOffset;
					addCellVertices(world->getCell(y, x), vertexZ);
					heightOffset += 0.1;
				}
			}
			heightOffset = 0.1;
		}
	}

}
