#ifndef ACTIONS_ACTION_H_
#define ACTIONS_ACTION_H_
#include "../World.h"
#include "SimpleAction.h"
class Action: public SimpleAction
{
public:
    Action();
    virtual ~Action();
    enum ACTION_TYPE  {
      AT_EAT=1,
      AT_MOVE=2,
      AT_END=4      
    } ;

    virtual void act ( World *world, CreaturePtr creature) =0;
    ACTION_TYPE const  & getType() const;
protected:
    ACTION_TYPE type;


};

#endif
