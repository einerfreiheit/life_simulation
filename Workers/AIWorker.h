#ifndef AIWORKER_H
#define AIWORKER_H

#include "WorldWorker.h"

class AIWorker : public WorldWorker
{
public:
    AIWorker();
    ~AIWorker();
    void move(World *world,int,int,int );
    void eat(World *world,int,int,int );
    bool ishungry(World *world,int,int,int);
    bool Alive(World *world,int);
    bool hungry;
    bool alive;

        int way;
        enum { down=0,up,left,right};

    void work(World *world) override;
};

#endif // AIWORKER_H
