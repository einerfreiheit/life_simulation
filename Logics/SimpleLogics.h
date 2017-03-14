#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_
#include "CreatureLogic.h"
#include "../Actions/Action.h"
#include "../Actions/Eat.h"//@ Eat и Move следует перенести в cpp, чтобы ограничить их видимость
#include "../Actions/Move.h"
#include <vector>

class SimpleLogics : public CreatureLogic {
public:
	SimpleLogics();
	virtual ~SimpleLogics();
//	std::vector <Action *> actions;
//	std::vector <Action *>  &getActions(){
//		return this->actions;
//	}
	void findFood(World*world,Creature &creature,std::vector<Action*> &actions) override;

};

#endif /* LOGICS_SIMPLELOGICS_H_ */
