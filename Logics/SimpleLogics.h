#ifndef LOGICS_SIMPLELOGICS_H_
#define LOGICS_SIMPLELOGICS_H_
#include "World.h"
#include <vector>

class SimpleLogics
{
public:
    void willToMove ( World*world, Creature&creature ) ;
    void willToEat ( Creature &creature ) ;
    void creatureWill(World * world, Creature & creature);
    int side =0;
    enum WAY_TYPE {
        WT_DOWN = 0, WT_UP, WT_LEFT, WT_RIGHT
    };
};


#endif /* LOGICS_SIMPLELOGICS_H_ */
