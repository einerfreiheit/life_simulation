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
	WaiterWorker(int N);
	int N;//@ имя переменной N не несёт в себе никакой информации о том, зачем она нужна - это плохо
	virtual ~WaiterWorker();
	void work (World *world) override;

};

#endif /* WORKERS_WAITERWORKER_H_ */
