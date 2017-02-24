/*
 * ResWorker.cpp
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#include "ResWorker.h"
#include <cstdlib>


ResWorker::ResWorker() {
	this->name = "ResWorker";
}

void ResWorker::work(World *world){
	mapHeight =world->mapHeight;
	mapWidth = world->mapWidth;
	rand_x=rand()%mapWidth;
	rand_y=rand()%mapHeight;
	if (world->map[rand_y][rand_x].life_res<=90)
		world->map[rand_y][rand_x].life_res=world->map[rand_y][rand_x].life_res+0.0;


}
ResWorker::~ResWorker() {
	// TODO Auto-generated destructor stub
}

