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
//	number=0;

}

void CreatureSpawnWorker::work(World *world){
	number=0;

	for (int i=0;i<3;i++){
		spawn_y=i;
		spawn_x=i;

		number=number+1;
		world->worm_map.resize(number);
		world->worm_map[number-1]= worm();
		world->worm_map[number-1].createWorm(spawn_y,spawn_x);
		world->worm_map[number-1].worm_energy=50.0;





}
}
CreatureSpawnWorker::~CreatureSpawnWorker() {
	// TODO Auto-generated destructor stub
}

