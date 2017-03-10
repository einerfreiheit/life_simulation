#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_
#include "CreatureLogic.h"
#include "../Actions/Action.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include <vector>

class SimpleLogics : public CreatureLogic {
public:
	SimpleLogics();
	virtual ~SimpleLogics();
	std::vector <Action *> actions;
	std::vector <Action *> getActions();
	void findFood(World*world,Creature &creature) override;

};

#endif /* LOGICS_SIMPLELOGICS_H_ */
