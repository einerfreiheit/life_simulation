#include "AIWorker.h"
#include "Logics/SimpleLogics.h"

AIWorker::AIWorker() {
	this->name = "AIWorker";

	simple = new SimpleLogics;

}

AIWorker::~AIWorker() {
	delete simple;

}

void AIWorker::work(World *world) {

	for (CreaturePtr creature : world->creatures) {
		simple->creatureWill(world, creature);

	}
}

