#include "ResourceWorker.h"
#include <cmath>
#include <cstdlib>

ResourceWorker::ResourceWorker() {
	this->name = "ResourceWorker";
	this->gainPerCell = SimulationData::getInst()->gainResourcePerCell;
	int height = SimulationData::getInst()->mapHeight;
	int width = SimulationData::getInst()->mapWidth;
	cellNumber = std::sqrt(height * width);
}

Cell *ResourceWorker::getRandom(World *world) {
	return world->getCell(rand() % world->map.size(), rand() % world->map[0].size());
}

void ResourceWorker::work(World *world) {

	while (cellNumber>0){
		getRandom(world)->food+=gainPerCell;
		cellNumber--;

	}
}

ResourceWorker::~ResourceWorker() {
}
