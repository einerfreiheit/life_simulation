#include "ResourceWorker.h"
#include <iostream>
#include <cstdlib>

ResourceWorker::ResourceWorker() {
	this->name = "ResourceWorker";

}
void ResourceWorker::setRandomXY(World *world) {
	rand_y = rand() % world->mapHeight;
	rand_x = rand() % world->mapWidth;

}
void ResourceWorker::setGainResource(double gainResourceToSet) {

	this->gainResource = gainResourceToSet;
}
void ResourceWorker::setNuberOfCellToGainResources(int numberOfCellToGain) {
	this->numberOfGainCell = numberOfCellToGain;
}
void ResourceWorker::work(World *world) {

	for (int i = 0; i <= numberOfGainCell; i++) {
		setRandomXY(world);
		if (world->map[rand_y][rand_x].food < (100.0 - gainResource)) {
			world->map[rand_y][rand_x].food += gainResource;
		}

	}
}
ResourceWorker::~ResourceWorker() {
}

