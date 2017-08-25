#include "OpenGLDynamicData.h"
#include <iostream>
#include <cmath>
OpenGLDynamicData::OpenGLDynamicData(World *world) {
	glGenBuffers(1, &waterBuffer);
	glGenBuffers(1, &creaturesBuffer);
	glGenBuffers(1,&waterIBO);

	waterBufferData.resize(world->map.size() * world->map[0].size()*20);

	glBindBuffer(GL_ARRAY_BUFFER, waterBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * waterBufferData.size(), &waterBufferData[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);



}

OpenGLDynamicData::~OpenGLDynamicData() {
}

void OpenGLDynamicData::getTextureUV(const float &vertexPosX, const float &vertexPosY) {

	float temp;
	float tX = vertexPosX / 128.0;
	float tY = vertexPosY / 128.0;

	water.push_back(tX);
	water.push_back(tY);

}
void OpenGLDynamicData::updateBuffers(World *world) {

	size_t mapHeight = world->map.size();
	size_t mapWidth = world->map[0].size();
	waterIndices.clear();
	float textureXcoord;
	float textureYcoord;
	float creatureZ = 0.01;
	int waterOffset = 0;
	waterIndex=0;
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
				waterBufferData[waterOffset] = fx;
				waterBufferData[waterOffset + 1] = fy;
				waterBufferData[waterOffset + 2] = waterZ;
				waterBufferData[waterOffset + 3] = fx * textureCoefficient;
				waterBufferData[waterOffset + 4] = fy * textureCoefficient;

				waterBufferData[waterOffset + 5] = fx + 1;
				waterBufferData[waterOffset + 6] = fy;
				waterBufferData[waterOffset + 7] = waterZ;
				waterBufferData[waterOffset + 8] = (fx + 1) * textureCoefficient;
				waterBufferData[waterOffset + 9] = fy * textureCoefficient;


				waterBufferData[waterOffset + 10] = fx;
				waterBufferData[waterOffset + 11] = fy + 1;
				waterBufferData[waterOffset + 12] = waterZ;
				waterBufferData[waterOffset + 13] = fx * textureCoefficient;
				waterBufferData[waterOffset + 14] = (fy + 1) * textureCoefficient;

				waterBufferData[waterOffset + 15] = fx + 1;
				waterBufferData[waterOffset + 16] = fy + 1;
				waterBufferData[waterOffset + 17] = waterZ;
				waterBufferData[waterOffset + 18] = (fx + 1) * textureCoefficient;
				waterBufferData[waterOffset + 19] = (fy + 1) * textureCoefficient;

				waterIndices.push_back(waterIndex+1);
				waterIndices.push_back(waterIndex+2);
				waterIndices.push_back(waterIndex);
				waterIndices.push_back(waterIndex+1);
				waterIndices.push_back(waterIndex+2);
				waterIndices.push_back(waterIndex+3);



				waterOffset+=20;
				waterIndex+=4;

			}
			if (cell->creaturesInCell.size() > 0) {
				for (auto creature : cell->creaturesInCell) {
					creatureZ = cell->height + cell->water + 0.1;

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

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,waterIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*waterIndices.size(),&waterIndices[0],GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	glBindBuffer(GL_ARRAY_BUFFER, waterBuffer);
	glBufferSubData(GL_ARRAY_BUFFER,0, waterIndex*5*sizeof(float), &waterBufferData[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, creaturesBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * creatures.size(), &creatures[0],
	GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	creatures.clear();

}
