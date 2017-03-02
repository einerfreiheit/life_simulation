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
	if (world->worm_map.size() > 0) {
		int index = world->worm_map.size() - 1;
		int i = 0;
		while (i < world->worm_map.size()) {

			if (world->worm_map[i].getEnergy() <= 0) {

				world->worm_map[i] = world->worm_map[index];
				index--;
				i--;
				if (index < 0)
					break;

			}
			i++;

		}
		if (index != world->worm_map.size() - 1)
			world->worm_map.resize(index+1);

		i=0;
		while (i<world->worm_map.size()){
			Creature & creature=world->worm_map[i];
			if (creature.getEnergy() > energyFissionThreshold){
				creature.setEnergy(creature.getEnergy()-lossFromFission);
				Creature secondCreature;
				secondCreature.setEnergy(100);
				secondCreature.setPosX(creature.getPosX());
				secondCreature.setPosY(creature.getPosY());
				world->worm_map.push_back(secondCreature);



			}

			i++;
		}

	}
}
CreatureSpawnWorker::~CreatureSpawnWorker() {
}

