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

}
void ResourseWorker::setRandomXY(World *world) {
	rand_y = rand() % world->mapHeight;
	rand_x = rand() % world->mapWidth;

}
void ResourseWorker::setGainResourse(double gainResoureToSet){

	this->gainResourse=gainResoureToSet;
}
void ResourseWorker:: setNuberOfCellToGainResourses (int numberOfCellToGain){
	this->numberOfGainCell=numberOfCellToGain;
}
void ResourseWorker::work(World *world) {

	for (int i = 0; i <= numberOfGainCell; i++) {
		setRandomXY(world);
		if (world->map[rand_y][rand_x].food < (100.0 - gainResourse)) {
			world->map[rand_y][rand_x].food += gainResourse;
		}

	}
}
ResourseWorker::~ResourseWorker() {
}

