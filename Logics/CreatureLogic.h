#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_
#include "../Creature.h"
#include "../World.h"
class CreatureLogic {
public:

	virtual void findFood (World*world,Creature &creature)=0;

};

#endif
