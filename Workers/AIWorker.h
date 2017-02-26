#ifndef AIWORKER_H
#define AIWORKER_H

#include "WorldWorker.h"
#include "CreatureLogic.h"

class AIWorker : public WorldWorker
{
public:
    AIWorker();
    ~AIWorker();
    void eat(Creature &creature, World *world,int y,int x );
    bool isAlive(World *world,Creature &creature);
    double energyFromFood =10;
    double creatureOneBait =5.0;
    CreatureLogic logic;


    void work(World *world) override;
};

#endif // AIWORKER_H
