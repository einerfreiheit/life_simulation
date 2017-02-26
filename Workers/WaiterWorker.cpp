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
	// TODO Auto-generated destructor stub
    //@ бесполезные эклипсовые комменты лучше удаляй, они не несут пользы (удаляй везде, а не только тут)
}

