#include "CreatureSpawnWorker.h"

CreatureSpawnWorker::CreatureSpawnWorker() {
	this->name = "CreatureSpawnWorker";

}

void CreatureSpawnWorker::work(World *world) {

	int lastId = (int) world->creatures.size() - 1;//@ lastId в таком виде был нужен только при удалении объектов
	for (int i = 0; i <= lastId; i++) {//@ можно заменить на годный range-based loop и будет изящнее
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

