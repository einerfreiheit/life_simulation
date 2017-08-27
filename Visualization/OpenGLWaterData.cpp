#include "OpenGLWaterData.h"

#include <iostream>
OpenGLWaterData::OpenGLWaterData() {

}

void OpenGLWaterData::initBuffers(World *world) {
	vertices.resize(world->map.size()*world->map[0].size()*4);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertices.size(), &vertices[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void OpenGLWaterData::computeBuffersData(World *world) {
	size_t mapHeight = world->map.size();
	size_t mapWidth = world->map[0].size();
	//vertices.resize(mapHeight*mapWidth);
	verticesToUpdate = 0;
	int vertexIndex = 0;
	float fx = 0.0;
	float fy = 0.0;
	float creatureZ = 0.01;
	Cell *cell = NULL;
	int heightGain;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			heightGain = 0;
			cell = &world->map[y][x];
			if (cell->water > 0.1) {
				fx = (float) x;
				fy = (float) y;
				float waterZ = cell->water + cell->height;

				vertices[verticesToUpdate].vertexPosition = glm::vec3(fx, fy, waterZ);
				vertices[verticesToUpdate].textureUV = glm::vec2(fx * textureDecrease, fy * textureDecrease);

				vertices[verticesToUpdate + 1].vertexPosition = glm::vec3(fx + 1, fy, waterZ);
				vertices[verticesToUpdate + 1].textureUV = glm::vec2((fx + 1) * textureDecrease, fy * textureDecrease);
				vertices[verticesToUpdate + 2].vertexPosition = glm::vec3(fx, fy + 1, waterZ);
				vertices[verticesToUpdate + 2].textureUV = glm::vec2(	(fx) * textureDecrease,
																		(fy + 1) * textureDecrease);
				vertices[verticesToUpdate + 3].vertexPosition = glm::vec3(fx + 1, fy + 1, waterZ);
				vertices[verticesToUpdate + 3].textureUV = glm::vec2(	(fx + 1) * textureDecrease,
																						(fy + 1) * textureDecrease);

				vertexIndices.push_back(verticesToUpdate + 1);
				vertexIndices.push_back(verticesToUpdate + 2);
				vertexIndices.push_back(verticesToUpdate);
				vertexIndices.push_back(verticesToUpdate + 1);
				vertexIndices.push_back(verticesToUpdate + 2);
				vertexIndices.push_back(verticesToUpdate + 3);
				verticesToUpdate += 4;

			}

		}
	}
}
