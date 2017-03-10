#ifndef WORKERS_CREATURESPAWNWORKER_H_
#define WORKERS_CREATURESPAWNWORKER_H_
#include "WorldWorker.h"
#include "Creature.h"
#include "../Factories/CreatureBuilder.h"

class CreatureSpawnWorker: public WorldWorker {
public:
	CreatureSpawnWorker();
	virtual ~CreatureSpawnWorker();
	void work(World *world) override;
	double lossFromFission = 300;
	double energyFissionThreshold = 600;

};

#endif
