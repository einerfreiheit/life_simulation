#include "ResourceWorker.h"
#include <cmath>
#include <cstdlib>

ResourceWorker::ResourceWorker() {
	this->name = "ResourceWorker";
	this->gainPerCell = SimulationData::getInst()->gainResourcePerCell;
	int height = SimulationData::getInst()->mapHeightToSet;
	int width = SimulationData::getInst()->mapWidthToSet;
	cellNumber = std::sqrt(height * width);
}

Cell *ResourceWorker::getRandom(World *world) {
	return world->getCell(rand() % world->map.size(), rand() % world->map[0].size());
}

void ResourceWorker::work(World *world) {

	while (cellNumber>0){
		randomCell = getRandom(world);
		randomCell->food+=gainPerCell;
		cellNumber--;

	}
}

ResourceWorker::~ResourceWorker() {
}
