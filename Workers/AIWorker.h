#ifndef AIWORKER_H
#define AIWORKER_H

#include "WorldWorker.h"
#include "CreatureLogic.h"

class AIWorker : public WorldWorker
{
public:
    AIWorker();
    ~AIWorker();
    CreatureLogic logic;
    void work(World *world) override;
};

#endif // AIWORKER_H
