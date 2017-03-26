#ifndef AIWORKER_H
#define AIWORKER_H
#include "WorldWorker.h"
#include "Logics/SimpleLogics.h"
#include "Logics/CreatureLogic.h"




class AIWorker: public WorldWorker {
public:
	AIWorker();
	virtual ~AIWorker();
//	SimpleLogics simplelogic;
	CreatureLogic *creaturelogic;
	void work(World *world) override;
};

#endif // AIWORKER_H
