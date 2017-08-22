#include "OpenGLDynamicData.h"
#include <iostream>
#include <cmath>
OpenGLDynamicData::OpenGLDynamicData() {
	glGenBuffers(1, &waterBuffer);
	glGenBuffers(1, &creaturesBuffer);


}

OpenGLDynamicData::~OpenGLDynamicData() {
}

void OpenGLDynamicData::getTextureUV(	const float &vertexPosX,
										const float &vertexPosY) {

	float temp;
	float tX = vertexPosX/128.0;
	float tY = vertexPosY/128.0;
	float textureX = ((((int)vertexPosX) % 64) / 64.0,1.0);
	float textureY = ((((int) vertexPosY )% 64) / 64.0,1.0);

	water.push_back(tX);
	water.push_back(tY);

}
void OpenGLDynamicData::updateBuffers(World *world) {

	size_t mapHeight = world->map.size();
	size_t mapWidth = world->map[0].size();
	float textureXcoord;
	float textureYcoord;
	float creatureZ = 0.01;
	Cell *cell = NULL;
	int heightGain;
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			heightGain = 0;
			float fx = (float) x;
			float fy = (float) y;
			cell = &world->map[y][x];
			if (cell->water > 0.1) {
				float waterZ = cell->water + cell->height;
				water.push_back(fx);
				water.push_back(fy);
				water.push_back(waterZ);
				getTextureUV(fx,fy);

				water.push_back(fx + 1);
				water.push_back(fy);
				water.push_back(waterZ);
				getTextureUV((fx+1),fy);

				water.push_back(fx);
				water.push_back(fy + 1);
				water.push_back(waterZ);
				getTextureUV(fx,(fy+1));

				water.push_back(fx + 1);
				water.push_back(fy + 1);
				water.push_back(waterZ);
				getTextureUV((fx+1),(fy+1));

			}
			if (cell->creaturesInCell.size() > 0) {
				for (auto creature : cell->creaturesInCell) {
					creatureZ = cell->height + cell->water +0.1;

					creatures.push_back(fx);
					creatures.push_back(fy);
					creatures.push_back(creatureZ + heightGain);
					creatures.push_back(0);
					creatures.push_back(0);



					creatures.push_back(fx + 1);
					creatures.push_back(fy);
					creatures.push_back(creatureZ + heightGain);
					creatures.push_back(1);
					creatures.push_back(0);



					creatures.push_back(fx);
					creatures.push_back(fy + 1);
					creatures.push_back(creatureZ + heightGain);
					creatures.push_back(0);
					creatures.push_back(1);


					creatures.push_back(fx + 1);
					creatures.push_back(fy + 1);
					creatures.push_back(creatureZ + heightGain);
					creatures.push_back(1);
					creatures.push_back(1);

					heightGain += 0.1;

				}

			}

		}

	}

	glBindBuffer(GL_ARRAY_BUFFER, waterBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * water.size(), &water[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, creaturesBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * creatures.size(), &creatures[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	creatures.clear();

}
