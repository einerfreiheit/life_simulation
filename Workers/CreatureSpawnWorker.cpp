/*
 * CreatureSpawnWorker.cpp
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#include "CreatureSpawnWorker.h"
#include <cstdlib>
#include "Creature.h"
CreatureSpawnWorker::CreatureSpawnWorker() {

}

void CreatureSpawnWorker::work(World *world) {

	int pos = 0;
	for (auto &creature : world->worm_map) {

		if (creature.getEnergy() == 0) {
			world->worm_map.erase(world->worm_map.begin() + pos);
		}

		if (creature.getEnergy() > energyFissionThreshold) {
			world->worm_map.resize(world->worm_map.size() + 1);
			Creature &newCreature = world->worm_map.back();
			creature.energy = creature.energy-lossFromFission;
			newCreature.x = creature.x;
			newCreature.y = creature.y;

		}
		pos++;
	}

}
CreatureSpawnWorker::~CreatureSpawnWorker() {
	// TODO Auto-generated destructor stub
}

