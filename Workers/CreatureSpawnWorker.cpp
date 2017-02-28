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
	this->name = "CreatureSpawnWorker";

}

void CreatureSpawnWorker::work(World *world) {
	int currentSize=world->worm_map.size();
	for (int i = 0; i <=currentSize; i++) {

		if (world->worm_map[i].getEnergy() <= 0) {
			world->worm_map.erase(world->worm_map.begin() + i);
			currentSize=currentSize-1;
			world->worm_map.resize(currentSize);
			i--;

		}

		for (int i = 0; i <= currentSize; i++) {
			Creature & creature=world->worm_map[i];
			if (creature.getEnergy() > energyFissionThreshold) {
				currentSize++;
				Creature newCreature;
				newCreature.setPosX(creature.x);
				newCreature.setPosY(creature.y);
				world->worm_map.push_back( newCreature);
				creature.energy = creature.energy - lossFromFission;


			}
		}
	}

}
CreatureSpawnWorker::~CreatureSpawnWorker() {
	// TODO Auto-generated destructor stub
}

