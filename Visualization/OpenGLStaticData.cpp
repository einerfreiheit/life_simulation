#include "OpenGLStaticData.h"
#include <algorithm>

OpenGLStaticData::OpenGLStaticData() {

}

OpenGLStaticData::~OpenGLStaticData() {

}

GLuint OpenGLStaticData::createData(World *world) {
	GLuint data = 0;
	size_t mapHeight = world->map.size();
	size_t mapWidth = world->map[0].size();

	getHeightDepth(world);
	double intensity = 0.0;
	size_t sizeData = 24 * mapHeight * mapWidth;
	mapData.resize(24 * mapHeight * mapWidth);

	float vertexZ;
	int offset;
	float vertexPosX;
	float vertexPosY;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			offset = 24 * (x + y * mapWidth);
			vertexZ = world->map[y][x].height;
			intensity = (vertexZ - minHeight) / (maxHeight - minHeight);
			vertexPosX = (float) x;
			vertexPosY = (float) y;
			mapData[offset] = vertexPosX;
			mapData[offset + 1] = vertexPosY;
			mapData[offset + 2] = vertexZ;
			mapData[offset + 3] = intensity;
			getTextureUV(vertexPosX, vertexPosY, mapData[offset + 4], mapData[offset + 5]);

			mapData[offset + 6] = vertexPosX;
			mapData[offset + 7] = (vertexPosY + 1.0);
			mapData[offset + 8] = vertexZ;
			mapData[offset + 9] = intensity;
			getTextureUV(vertexPosX, vertexPosY + 1, mapData[offset + 10], mapData[offset + 11]);

			mapData[offset + 12] = (vertexPosX + 1.0);
			mapData[offset + 13] = vertexPosY;
			mapData[offset + 14] = vertexZ;
			mapData[offset + 15] = intensity;
			getTextureUV((vertexPosX + 1), vertexPosY, mapData[offset + 16], mapData[offset + 17]);

			mapData[offset + 18] = (vertexPosX + 1.0);
			mapData[offset + 19] = (vertexPosY + 1.0);
			mapData[offset + 20] = vertexZ;
			mapData[offset + 21] = intensity;
			getTextureUV((vertexPosX + 1), (vertexPosY + 1), mapData[offset + 22], mapData[offset + 23]);

		}
	}
	glGenBuffers(1, &data);
	glBindBuffer(GL_ARRAY_BUFFER, data);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mapData.size(), &mapData[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	return data;

}

void OpenGLStaticData::getTextureUV(const float &vertexPosX,
									const float &vertexPosY,
									float &textureX,
									float &textureY) {
	textureX = ((int) vertexPosX % 64) / 64.0;
	textureY = ((int) vertexPosY % 64) / 64.0;
}

void OpenGLStaticData::getHeightDepth(World *world) {

	float cellHeight = 0.0;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			cellHeight = world->map[i][j].height;
			maxHeight = std::max(maxHeight, cellHeight);
			minHeight = std::min(minHeight, cellHeight);
		}
	}

}

