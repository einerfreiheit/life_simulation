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

}
void WaiterWorker::setWaitingTime(int timeToWait){
	this->waitingTime=timeToWait;


}
void WaiterWorker::work(World *world){
	usleep(waitingTime);
}
WaiterWorker::~WaiterWorker() {
}

