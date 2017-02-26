/*
 * WaiterWorker.cpp
 *
 *  Created on: 22 февр. 2017 г.
 *      Author: lenovo
 */

#include "WaiterWorker.h"
#include <unistd.h>

WaiterWorker::WaiterWorker(int setWaitingTime) {
	this->name = "WaiterWorker";
	this->waitingTime=setWaitingTime;
}

void WaiterWorker::work(World *world){
	usleep(waitingTime);
}
WaiterWorker::~WaiterWorker() {
}

