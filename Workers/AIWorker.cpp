#include "AIWorker.h"

AIWorker::AIWorker() {
	this->name = "AIWorker";

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {

	for (auto creature : world->creatures) {

		simplelogic.findFood(world, *creature);

	}
}

