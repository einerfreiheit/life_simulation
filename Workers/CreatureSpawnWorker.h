#ifndef WORKERS_CREATURESPAWNWORKER_H_
#define WORKERS_CREATURESPAWNWORKER_H_

#include "WorldWorker.h"


class CreatureSpawnWorker: public WorldWorker {
public:
	CreatureSpawnWorker();
	virtual ~CreatureSpawnWorker();
	void work(World *world) override;

};

#endif
