#include "ResourceFactory.h"
#include "../SimulationData.h"

void ResourceFactory::addWater(World* world) {
	double water = SimulationData::getInst()->waterPerCell;
	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			world->map[y][x].water = water;
		}
	}

}
