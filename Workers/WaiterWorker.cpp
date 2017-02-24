/*
 * WaiterWorker.cpp
 *
 *  Created on: 22 февр. 2017 г.
 *      Author: lenovo
 */

#include "WaiterWorker.h"
#include <unistd.h>

WaiterWorker::WaiterWorker(int time) {//@ имя time плохо использовать для переменной. Как минимум потому, что есть функция time в time.h
    //@ нужно переименовать как-нибудь вроде waitTime - ты одновременно показываешь, что это время, а ещё и говоришь доп инфу
	this->name = "WaiterWorker";
	this->N=time;
}

void WaiterWorker::work(World *world){
	usleep(N);
}
WaiterWorker::~WaiterWorker() {
	// TODO Auto-generated destructor stub
    //@ бесполезные эклипсовые комменты лучше удаляй, они не несут пользы (удаляй везде, а не только тут)
}

