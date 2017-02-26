/*
 * WaiterWorker.h
 *
 *  Created on: 22 февр. 2017 г.
 *      Author: lenovo
 */

#ifndef WORKERS_WAITERWORKER_H_
#define WORKERS_WAITERWORKER_H_
#include "WorldWorker.h"


class WaiterWorker: public WorldWorker {
public:
	WaiterWorker(int setWaitingTime);
	virtual ~WaiterWorker();
	void work (World *world) override;
	int waitingTime;

};

#endif /* WORKERS_WAITERWORKER_H_ */
