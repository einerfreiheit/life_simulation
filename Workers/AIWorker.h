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
    bool isHungry(World *world,int y,int x);//@ а если кто-нибудь заглянет в хедер и увидит эти int, int, int, он разберётся, что каждый int должен означать?
    bool isAlive(World *world,Creature &creature);
    CreatureLogic logic;


    void work(World *world) override;
};

#endif // AIWORKER_H
