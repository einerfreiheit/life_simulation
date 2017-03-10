#include "CreatureSpawnWorker.h"

CreatureSpawnWorker::CreatureSpawnWorker() {
	this->name = "CreatureSpawnWorker";
	this->isAvailable =
			SimulationData::getInst()->CreatureSpawnWorkerIsAvailable;

}

void CreatureSpawnWorker::work(World *world) {

	int lastId = (int) world->creatures.size() - 1;
	for (int i = 0; i <= lastId; i++) {
		Creature *current = world->creatures[i];
		if (current->getEnergy() > energyFissionThreshold) {
			current->setEnergy(current->getEnergy() - lossFromFission);
			Creature *second = CreatureBuilder::build(current->getPosX(),
					current->getPosY());
			world->creatures.push_back(second);
		}
	}
}

CreatureSpawnWorker::~CreatureSpawnWorker() {
}

