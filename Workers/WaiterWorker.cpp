/*
 * WaiterWorker.cpp
 *
 *  Created on: 22 февр. 2017 г.
 *      Author: lenovo
 */

#include "WaiterWorker.h"
#include <unistd.h>

WaiterWorker::WaiterWorker(int time) {
	this->name = "WaiterWorker";
	this->N=time;
}

void WaiterWorker::work(World *world){
	usleep(N);
}
WaiterWorker::~WaiterWorker() {
	// TODO Auto-generated destructor stub
}

