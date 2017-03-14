#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_
#include "../Creature.h"
#include "../World.h"
#include "../Actions/Action.h"
class CreatureLogic {
public:

	virtual void findFood (World*world,Creature &creature,std::vector<Action*> &actions)=0;

};

#endif
