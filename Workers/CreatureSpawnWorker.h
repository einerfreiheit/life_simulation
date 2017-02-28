/*
 * CreatureSpawnWorker.h
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#ifndef WORKERS_CREATURESPAWNWORKER_H_
#define WORKERS_CREATURESPAWNWORKER_H_
#include "WorldWorker.h"
#include "Creature.h"

class CreatureSpawnWorker : public WorldWorker {
public:
	CreatureSpawnWorker();
	virtual ~CreatureSpawnWorker();
	void work(World *world) override;
	double lossFromFission = 100;
	double energyFissionThreshold=600;

};

#endif /* WORKERS_CREATURESPAWNWORKER_H_ */
