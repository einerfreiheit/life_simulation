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
	world->map[rand()%mapHeight][rand()%mapWidth].life_res =+ rand()%10;


}
ResWorker::~ResWorker() {
	// TODO Auto-generated destructor stub
}

