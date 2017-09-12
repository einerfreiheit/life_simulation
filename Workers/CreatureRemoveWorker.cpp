#include "CreatureRemoveWorker.h"
#include <iostream>

CreatureRemoveWorker::CreatureRemoveWorker() {
	this->name = "CreatureRemoveWorker";
}

void CreatureRemoveWorker::work(World *world) {

	int lastId = world->creatures.size() - 1;
	int lastIdBefore = lastId;
	int i = 0;
	while (i <= lastId) {
		CreaturePtr creature = world->creatures[i];
		if (creature->energy <= 0 || creature->phenotype->healthPoints <= 0) {
			creature->stats->updateGenomeComlexity(creature->getGenome());
			creature->stats->writeStatistics();
			world->getCell(creature->y, creature->x)->removeCreature(creature->getId());
			world->creatures[i] = world->creatures[lastId];
			lastId--;

		}
		else {
			i++;
		}
	}
	if (lastId != lastIdBefore) {
		world->creatures.resize(lastId + 1);

	}
}
CreatureRemoveWorker::~CreatureRemoveWorker() {
}

