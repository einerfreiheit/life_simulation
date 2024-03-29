#include "CreatureSpawnWorker.h"
#include "Creature.h"
#include "../Factories/CreatureBuilder.h"
#include <stdexcept>

CreatureSpawnWorker::CreatureSpawnWorker() {
	this->name = "CreatureSpawnWorker";

}

void CreatureSpawnWorker::work(World *world) {
	std::vector<CreaturePtr> newborn;
	for (CreaturePtr creature : world->creatures) {
		if (creature->energy > creature->phenotype->fissionThreshold) {
			creature->energy -= creature->phenotype->fissionLoss;
			CreaturePtr second = CreatureBuilder::build(world, creature);
			newborn.push_back(second);
			creature->stats->incrementFissionsNumber();
		}
	}

	world->creatures.insert(world->creatures.end(), newborn.begin(), newborn.end());
	if (world->creatures.size() >= 100) {
		throw std::runtime_error("creatures more than 100");
	}
}

CreatureSpawnWorker::~CreatureSpawnWorker() {
}

