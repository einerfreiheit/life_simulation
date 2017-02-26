/*
 * ResWorker.cpp
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#include "ResourseWorker.h"

#include <cstdlib>


ResourseWorker::ResourseWorker() {
	this->name = "ResourseWorker";
}

void ResourseWorker::work(World *world){
	rand_x=rand()% world->mapHeight;;
	rand_y=rand()% world->mapWidth;
	if (world->map[rand_y][rand_x].food<=90)
		world->map[rand_y][rand_x].food=world->map[rand_y][rand_x].food+gainResourse;//волшебная константа прироста ресурса должна быть вынесена куда-то на видное место, мб в хедер


}
ResourseWorker::~ResourseWorker() {
	// TODO Auto-generated destructor stub
}

