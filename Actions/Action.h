#ifndef ACTIONS_ACTION_H_
#define ACTIONS_ACTION_H_
#include "../World.h"
#include "SimpleAction.h"
#include "SimulationData.h"
class Action :public SimpleAction {
public:
	Action();
	 ~Action();
	virtual void act(World *world, Creature &creature) =0;

};

#endif
