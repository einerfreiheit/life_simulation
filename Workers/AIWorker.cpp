#include "AIWorker.h"

AIWorker::AIWorker() {
	this->name = "AIWorker";
	this->creaturelogic = new SimpleLogics;

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {

	for (auto creature : world->creatures) {

		creaturelogic->logicActions(world,*creature);

	}
}

