#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_
#include "World.h"
#include <vector>

class SimpleLogics
{
public:
    void willToMove ( World *world, CreaturePtr creature ) ;
    void willToEat ( CreaturePtr creature );
    void creatureWill(World *world, CreaturePtr creature);

};


#endif /* LOGICS_SIMPLELOGICS_H_ */
