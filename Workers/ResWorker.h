/*
 * ResWorker.h
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#ifndef WORKERS_RESWORKER_H_
#define WORKERS_RESWORKER_H_
#include "WorldWorker.h"

class ResWorker: public WorldWorker {
public:
	ResWorker();
	virtual ~ResWorker();
    void work(World *world) override;
    int mapHeight;
    int mapWidth;
    int rand_y;
    int rand_x;

};

#endif /* WORKERS_RESWORKER_H_ */
