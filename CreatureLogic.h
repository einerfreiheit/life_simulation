#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_
#include "Creature.h"
class CreatureLogic {
public:
	CreatureLogic();
	virtual ~CreatureLogic();
	void move(World *world, Creature &creature);
	void eat(Creature &creature, World *world);
	double energyFromFood = 10;
	double creatureOneBait = 5.0;

	int way;
	enum WAY_TYPE {
		WT_DOWN = 0, WT_UP, WT_LEFT, WT_RIGHT
	};

};

#endif