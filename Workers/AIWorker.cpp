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
		eat.Act(world, *creature);
		move.Act(world, *creature);
		std::cout << creature->energy << std::endl;

	}
}

