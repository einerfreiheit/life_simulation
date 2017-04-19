#ifndef ACTIONS_ACTION_H_
#define ACTIONS_ACTION_H_
#include "../World.h"
#include "SimpleAction.h"
#include "SimulationData.h"
class Action: public SimpleAction
{
public:
    Action() {
    }
    ;
    virtual ~Action() {
      
    }
    ;
    
              enum ACTION_TYPE  {AT_EAT=1,AT_MOVE=2};
	      ACTION_TYPE type;
	      uint8_t mask=0;

    
    virtual void act ( World *world, Creature &creature ) =0;
    
    

};

#endif
