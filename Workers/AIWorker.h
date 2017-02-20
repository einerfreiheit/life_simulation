#ifndef AIWORKER_H
#define AIWORKER_H

#include "WorldWorker.h"

class AIWorker : public WorldWorker
{
public:
    AIWorker();
    ~AIWorker();
    
    void work(World *world) override;
};

#endif // AIWORKER_H
