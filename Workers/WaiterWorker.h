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
	WaiterWorker();
	void setWaitingTime(int timeToWait);
	virtual ~WaiterWorker();
	int waitingTime;
	void work (World *world) override;

};

#endif /* WORKERS_WAITERWORKER_H_ */
