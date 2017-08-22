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
	//mapData.resize(24 * mapHeight * mapWidth);

	float vertexZ;
	int offset;
	float vertexPosX;
	float vertexPosY;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			offset = 20 * (x + y * mapWidth);
			vertexZ = world->map[y][x].height;
			intensity = (vertexZ - minHeight) / (maxHeight - minHeight);
			vertexPosX = (float) x;
			vertexPosY = (float) y;
			mapData.push_back(vertexPosX);
			mapData.push_back(vertexPosY);
			mapData.push_back(vertexZ);
		//	mapData[offset + 3] = intensity;
			getTextureUV(vertexPosX, vertexPosY);

			mapData.push_back(vertexPosX);
			mapData.push_back (vertexPosY + 1.0);
			mapData.push_back(vertexZ);
		//	mapData[offset + 9] = intensity;
			getTextureUV(vertexPosX, vertexPosY + 1);

			mapData.push_back(vertexPosX + 1.0);
			mapData.push_back(vertexPosY);
			mapData.push_back(vertexZ);
			//mapData[offset + 15] = intensity;
			getTextureUV((vertexPosX + 1), vertexPosY);

			mapData.push_back(vertexPosX + 1.0);
			mapData.push_back(vertexPosY + 1.0);
			mapData.push_back(vertexZ);
			//mapData[offset + 21] = intensity;
			getTextureUV((vertexPosX + 1), (vertexPosY + 1));

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
									const float &vertexPosY) {
	float textureX = vertexPosX/64.0;;
	float textureY = vertexPosY/64.0;
	mapData.push_back(textureX);
	mapData.push_back(textureY);
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

