#include "AIWorker.h"
#include <iostream>

AIWorker::AIWorker() {
	this->name = "AIWorker";
	this->isAvailable = SimulationData::getInst()->AIWorkerIsAvailable;

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {
	for (auto creature : world->creatures) {
		eat.act(world, *creature);
		move.act(world, *creature);
		std::cout << creature->energy << std::endl;

	}
}

