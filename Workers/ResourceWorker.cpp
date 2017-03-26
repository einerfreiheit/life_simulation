#include "ResourceWorker.h"
#include <cmath>
#include <cstdlib>
ResourceWorker::ResourceWorker() {
	this->name = "ResourceWorker";
	this->gainPerCell = SimulationData::getInst()->gainResourcePerCell;

}

void ResourceWorker::getRandom(int&value, int border) {
	value = rand() % border;

}
void ResourceWorker::work(World *world) {
	int &height = world->mapHeight;
	int &width = world->mapWidth;
	int cellNumber = (int) (sqrt(height * width));
	double cellGain = height * width * gainPerCell / cellNumber;
	for (int i = 0; i <= cellNumber; i++) {
		int randX;
		int randY;
		getRandom(randX, width);
		getRandom(randY, height);
		if (world->map[randY][randY].food < (100.0 - cellGain)) {
			world->map[randX][randY].food += cellGain;
		}

	}
}
ResourceWorker::~ResourceWorker() {
}

