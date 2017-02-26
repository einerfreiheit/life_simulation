
#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_
#include "Creature.h"
class CreatureLogic  {
public:
	CreatureLogic();
	virtual ~CreatureLogic();
	void move(Creature  &creature, int borderY, int borderX);

	int way;
	enum {
		down = 0, up, left, right
	};

};

#endif
