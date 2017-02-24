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
	int spawn_y;
	int spawn_x;
	int number;

};

#endif /* WORKERS_CREATURESPAWNWORKER_H_ */
