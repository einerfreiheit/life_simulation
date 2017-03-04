#include "AIWorker.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

AIWorker::AIWorker() {
	this->name = "AIWorker";

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {

	for (auto creature : world->creatures) {
		logic.eat(*creature,world);
		logic.move(world,*creature);
		std::cout<<creature->energy<<std::endl;

	}
}


