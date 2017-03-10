#include "AIWorker.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

AIWorker::AIWorker() {
	this->name = "AIWorker";
	this->isAvailable=SimulationData::getInst()->AIWorkerIsAvailable;

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {

	for (auto creature : world->creatures) {
		logic.eat(world,*creature);
		logic.move(world,*creature);
		std::cout<<creature->energy<<std::endl;

	}
}


