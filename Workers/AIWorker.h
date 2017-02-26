#ifndef AIWORKER_H
#define AIWORKER_H

#include "WorldWorker.h"
#include "CreatureLogic.h"

class AIWorker : public WorldWorker
{
public:
    AIWorker();
    ~AIWorker();
    void move(World *world,int,int,int );
    void eat(Creature &creature, World *world,int,int );
    bool ishungry(World *world,int,int);//@ а если кто-нибудь заглянет в хедер и увидит эти int, int, int, он разберётся, что каждый int должен означать?
    bool Alive(World *world,int);
    CreatureLogic logic;

    bool hungry;
    bool alive; //@ делай локальные переменные внутри методов, а не выноси из методов все переменные в хедер класса - они же относятся к его промежуточной работе, а не к нему самому
    int way;
          enum { down=0,up,left,right};

    void work(World *world) override;
};

#endif // AIWORKER_H
