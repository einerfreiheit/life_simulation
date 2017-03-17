#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_
#include "CreatureLogic.h"
#include "Creature.h"
#include "Actions/SimpleAction.h"
#include "../Actions/Action.h"
#include "../Actions/Eat.h"//@ Eat и Move следует перенести в cpp, чтобы ограничить их видимость
#include "../Actions/Move.h"
#include <vector>

class SimpleLogics : public CreatureLogic {
public:
	SimpleLogics();
	virtual ~SimpleLogics();
	void findFood(World*world,Creature &creature) override;

};

#endif /* LOGICS_SIMPLELOGICS_H_ */
