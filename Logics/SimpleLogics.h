#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_

#include "World.h"
#include <vector>

class SimpleLogics {
public:
	void willToMove(CreaturePtr creature);
	void willToEat(CreaturePtr creature);
	void willToAttack(CreaturePtr creature);
	void creatureWill(World *world, CreaturePtr creature);
};

#endif
