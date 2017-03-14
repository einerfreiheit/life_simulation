#ifndef AIWORKER_H
#define AIWORKER_H
#include "../Actions/Action.h"
#include "WorldWorker.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include "../Logics/SimpleLogics.h"
#include "../Logics/CreatureLogic.h"


class AIWorker: public WorldWorker {
public:
	AIWorker();
	~AIWorker();
//	std::vector<Action> &actions;

	SimpleLogics simplelogic;


	void work(World *world) override;
};

#endif // AIWORKER_H
