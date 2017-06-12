#include <iostream>
#include "ResourceFactory.h"
#include "../SimulationData.h"
#include <iostream>

void ResourceFactory::addWater(World* world) {
	int height = world->mapHeight;
	int width = world->mapWidth;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			world->map[y][x].water = SimulationData::getInst()->allWaterAmount / (height * width);

		}
	}

}
