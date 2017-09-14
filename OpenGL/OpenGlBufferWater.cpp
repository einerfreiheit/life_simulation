#include "OpenGlBufferWater.h"
#include <iostream>

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
	static int streamDirection=1;
	float vertexZ;
	Cell *cell = NULL;
	static float offset = 0.0;

	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			cell = world->getCell(y, x);
			if (cell->water > 0.1) {
				vertexZ = cell->height + cell->water;
				addWater(world->getCell(y, x), offset);

			}

		}
	}
	if ( streamDirection==1) {
		offset += 0.001;
	}
	 if (streamDirection==-1) {
		offset-=0.001;
	}

	 if (offset>0.1 || offset<-0.1){
		 streamDirection*=-1;
	 }
	 std::cout<<offset<<" offset "<<std::endl;


}

void OpenGlBufferWater::addWater(Cell*cell, float textureOffset) {
	float fx = cell->x;
	float fy = cell->y;

	indices[indicesToUpate] = verticesToUpdate + 1;
	indices[indicesToUpate + 1] = verticesToUpdate + 2;
	indices[indicesToUpate + 2] = verticesToUpdate;
	indices[indicesToUpate + 3] = verticesToUpdate + 1;
	indices[indicesToUpate + 4] = verticesToUpdate + 2;
	indices[indicesToUpate + 5] = verticesToUpdate + 3;
	indicesToUpate += 6;

	float waterLevel = (cell->heights[0][0] + cell->heights[0][1] + cell->heights[1][0] + cell->heights[1][1]) / 4
			+ cell->water;

	vertices[verticesToUpdate].x = fx;
	vertices[verticesToUpdate].y = fy;
	vertices[verticesToUpdate].z = waterLevel;
	vertices[verticesToUpdate].textureX = fx * objectTextureSize + textureOffset;
	vertices[verticesToUpdate].textureY = fy * objectTextureSize + textureOffset;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx + 1;
	vertices[verticesToUpdate].y = fy;
	vertices[verticesToUpdate].z = waterLevel;
	vertices[verticesToUpdate].textureX = (fx + 1) * objectTextureSize + textureOffset;
	vertices[verticesToUpdate].textureY = fy * objectTextureSize + textureOffset;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx;
	vertices[verticesToUpdate].y = fy + 1;
	vertices[verticesToUpdate].z = waterLevel;
	vertices[verticesToUpdate].textureX = fx * objectTextureSize + textureOffset;
	vertices[verticesToUpdate].textureY = (fy + 1) * objectTextureSize + textureOffset;
	verticesToUpdate++;

	vertices[verticesToUpdate].x = fx + 1;
	vertices[verticesToUpdate].y = fy + 1;
	vertices[verticesToUpdate].z = waterLevel;
	vertices[verticesToUpdate].textureX = (fx + 1) * objectTextureSize + textureOffset;
	vertices[verticesToUpdate].textureY = (fy + 1) * objectTextureSize + textureOffset;
	verticesToUpdate++;

}

