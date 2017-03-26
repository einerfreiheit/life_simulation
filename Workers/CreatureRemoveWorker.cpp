#include "CreatureRemoveWorker.h"

CreatureRemoveWorker::CreatureRemoveWorker() {
	this->name = "CreatureRemoveWorker";

}

void CreatureRemoveWorker::work(World *world) {

	int lastId = (int) world->creatures.size() - 1;
	int lastIdBefore=lastId;
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
	if (lastId != lastIdBefore) {
		world->creatures.resize(lastId + 1); //@ надо почитать или протестировать ресайз. Что будет, если ресайз идёт к тому же самому размеру? Медленно ли это?
	}
}
CreatureRemoveWorker::~CreatureRemoveWorker() {
}

