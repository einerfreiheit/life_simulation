#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_
#include "CreatureLogic.h"
#include "Creature.h"
#include "Actions/SimpleAction.h"
#include "../Actions/Action.h"

#include <vector>

class SimpleLogics: public CreatureLogic {
public:
	SimpleLogics();
	virtual ~SimpleLogics();
	void findFood(World*world, Creature &creature) override;
	void logicMove(World*world, Creature&creature) override;
	void logicEat(Creature &creature) override;

	int side;
			enum WAY_TYPE {
				WT_DOWN = 0, WT_UP, WT_LEFT, WT_RIGHT
			};
	};


#endif /* LOGICS_SIMPLELOGICS_H_ */
