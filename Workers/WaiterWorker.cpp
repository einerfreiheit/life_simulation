/*
 * WaiterWorker.cpp
 *
 *  Created on: 22 февр. 2017 г.
 *      Author: lenovo
 */

#include "WaiterWorker.h"
#include <unistd.h>

WaiterWorker::WaiterWorker() {
	this->name = "WaiterWorker";
	this->isAvailable=SimulationData::getInst()->WaiterWorkerIsAvailable;
	this->waitingTime=SimulationData::getInst()->timeToWait;

}

void WaiterWorker::work(World *world){
	usleep(waitingTime);
}
WaiterWorker::~WaiterWorker() {
}

