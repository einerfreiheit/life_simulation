#include "ResourceWorker.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

ResourceWorker::ResourceWorker() {
	this->name = "ResourceWorker";
	this->isAvailable=SimulationData::getInst()->ResourceWorkerIsAvailable;
	this->gainPerCell=SimulationData::getInst()->gainResourcePerCell;

}
void ResourceWorker::setRandomXY(World *world) {
	rand_y = rand() % world->mapHeight;
	rand_x = rand() % world->mapWidth;

}

void ResourceWorker::work(World *world) {
	int cellNumber = (int )(sqrt(world->mapHeight*world->mapWidth));
	double cellGain = (world->mapHeight*world->mapWidth)*gainPerCell/cellNumber;
	for (int i = 0; i <= cellNumber; i++) {
		setRandomXY(world);
		if (world->map[rand_y][rand_x].food < (100.0 - cellGain)) {
			world->map[rand_y][rand_x].food += cellGain;
		}

	}
}
ResourceWorker::~ResourceWorker() {
}

