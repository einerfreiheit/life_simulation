
#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_
#include "Creature.h"
class CreatureLogic  {
public:
	CreatureLogic();
	virtual ~CreatureLogic();
	void move(Creature  &creature, int borderY, int borderX);

	int way;
	enum WAY_TYPE{
		WT_DOWN = 0, WT_UP, WT_LEFT, WT_RIGHT
	};

};

#endif
