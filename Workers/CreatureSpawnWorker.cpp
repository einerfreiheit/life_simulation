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


	world->worm_map.resize(world->worm_map.size()+1);

}
CreatureSpawnWorker::~CreatureSpawnWorker() {
	// TODO Auto-generated destructor stub
}

