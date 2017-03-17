#ifndef WORKERS_CREATUREACTIONWORKER_H_
#define WORKERS_CREATUREACTIONWORKER_H_
#include "WorldWorker.h"
#include "../Creature.h"
#include "../Logics/SimpleLogics.h"
#include "../Logics/CreatureLogic.h"
class CreatureActionWorker :public WorldWorker {
public:
	CreatureActionWorker();
	virtual ~CreatureActionWorker();
	void work(World *world) override;
	SimpleLogics simplelogics;

};

#endif /* WORKERS_CREATUREACTIONWORKER_H_ */
