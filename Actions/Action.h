#ifndef ACTIONS_ACTION_H_
#define ACTIONS_ACTION_H_
#include "../World.h"
class Action {
public:
	Action();
	virtual ~Action();
	virtual void act(World *world, Creature &creature) =0;
};

#endif
