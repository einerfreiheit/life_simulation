#ifndef ACTIONS_EAT_H_
#define ACTIONS_EAT_H_

#include "Action.h"

class Eat: public  Action
{
public:
    Eat();
    virtual  ~Eat();
    void act ( World *world, CreaturePtr creature ) override;

};

#endif
