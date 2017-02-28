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

void ResourseWorker::work(World *world) {


		rand_y = rand() % world->mapHeight;
		rand_x = rand() % world->mapWidth;

		if (world->map[rand_y][rand_x].food < (100-gainResourse)){
			world->map[rand_y][rand_x].food += gainResourse;
		}


}
ResourseWorker::~ResourseWorker() {
}

