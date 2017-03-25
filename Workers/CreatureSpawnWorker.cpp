#include "CreatureSpawnWorker.h"

CreatureSpawnWorker::CreatureSpawnWorker() {
	this->name = "CreatureSpawnWorker";

}

void CreatureSpawnWorker::work(World *world) {

	for (Creature *creature : world->creatures) {
		if (creature->getEnergy() > energyFissionThreshold) {
			creature->setEnergy(creature->getEnergy() - lossFromFission);
			Creature *second = CreatureBuilder::build(creature->getPosX(),
					creature->getPosY());
			world->creatures.push_back(second);
		}
	}
}

CreatureSpawnWorker::~CreatureSpawnWorker() {
}

