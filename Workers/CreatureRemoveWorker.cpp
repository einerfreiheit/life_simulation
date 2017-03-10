#include "CreatureRemoveWorker.h"

CreatureRemoveWorker::CreatureRemoveWorker() {
	this->name = "CreatureRemoveWorker";
	this->isAvailable=SimulationData::getInst()->CreatureRemoveWorkerIsAvailable;

}

void CreatureRemoveWorker::work(World *world) {

	if (!world->creatures.size()) {
		return;
	}

	int lastId = (int) world->creatures.size() - 1;
	int i = 0;
	while (i <= lastId) {
		Creature *current = world->creatures[i];
		if (current->getEnergy() <= 0) {
			delete current;
			world->creatures[i] = world->creatures[lastId];
			lastId--;
		} else {
			i++;
		}
	}
	world->creatures.resize(lastId + 1);

}
CreatureRemoveWorker::~CreatureRemoveWorker() {
}

