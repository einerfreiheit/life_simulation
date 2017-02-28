/*
 * ResWorker.cpp
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#include "ResourseWorker.h"
#include <iostream>
#include <cstdlib>

ResourseWorker::ResourseWorker() {
	this->name = "ResourseWorker";
	rand_x = 0;
	rand_y = 0;
}
void ResourseWorker::setRandomXY(World *world) {
	this->rand_y = rand() % world->mapHeight;
	this->rand_x = rand() % world->mapWidth;
	std::cout << rand_y << std::endl;
	std::cout << rand_x << std::endl;

}
void ResourseWorker::work(World *world) {
	std::cout << "start"<<std::endl;
	for (int i = 0; i <= 10; i++) {
		setRandomXY(world);
		if (world->map[rand_y][rand_x].food < (100.0 - gainResourse)) {
			world->map[rand_y][rand_x].food += gainResourse;
		}

	}
}
ResourseWorker::~ResourseWorker() {
}

