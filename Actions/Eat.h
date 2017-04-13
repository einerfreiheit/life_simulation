#ifndef ACTIONS_EAT_H_
#define ACTIONS_EAT_H_
#include "Action.h"

class Eat: public  Action
{
public:
	Eat();
	 ~Eat();
	void act(World *world,Creature &creature) override;
};

#endif
