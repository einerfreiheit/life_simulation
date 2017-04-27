
#ifndef ATTACK_H
#define ATTACK_H
#include "Action.h"
class Attack : public Action
{
public: 
    Attack();
    virtual ~Attack();
     void act ( World *world, CreaturePtr creature) override;
private:
     void attack(CreaturePtr actor, CreaturePtr victim);

};

#endif // ATTACK_H
