#include "OpenGLCreaturesData.h"

OpenGLCreaturesData::OpenGLCreaturesData() {
}

void OpenGLCreaturesData::initBuffers(World *world) {
	vertices.resize(100*4); //пока так

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertices.size(), &vertices[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void OpenGLCreaturesData::computeBuffersData(World *world) {

	size_t mapHeight = world->map.size();
	size_t mapWidth = world->map[0].size();
	float textureXcoord;
	float textureYcoord;
	verticesToUpdate = 0;
	float creatureZ = 0.01;
	Cell *cell = NULL;
	float heightOffset = 0.0;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			float fx = (float) x;
			float fy = (float) y;
			cell = &world->map[y][x];

			if (cell->creaturesInCell.size() > 0) {
				for (auto creature : cell->creaturesInCell) {
					creatureZ = cell->height + cell->water + heightOffset+0.1;

					vertices[verticesToUpdate].vertexPosition = glm::vec3(fx, fy, creatureZ);
					vertices[verticesToUpdate].textureUV = glm::vec2(0, 0);
					vertices[verticesToUpdate + 1].vertexPosition = glm::vec3(fx + 1, fy, creatureZ);
					vertices[verticesToUpdate + 1].textureUV = glm::vec2(1, 0);
					vertices[verticesToUpdate + 2].vertexPosition = glm::vec3(fx, fy + 1, creatureZ);
					vertices[verticesToUpdate + 2].textureUV = glm::vec2(0, 1);
					vertices[verticesToUpdate + 3].vertexPosition = glm::vec3(fx + 1, fy + 1, creatureZ);
					vertices[verticesToUpdate + 3].textureUV = glm::vec2(1, 1);

					vertexIndices.push_back(verticesToUpdate + 1);
					vertexIndices.push_back(verticesToUpdate + 2);
					vertexIndices.push_back(verticesToUpdate);
					vertexIndices.push_back(verticesToUpdate + 1);
					vertexIndices.push_back(verticesToUpdate + 2);
					vertexIndices.push_back(verticesToUpdate + 3);
					verticesToUpdate += 4;

					heightOffset += 0.1;
				}
				heightOffset = 0;
			}

		}

	}

}
