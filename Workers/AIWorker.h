#ifndef AIWORKER_H
#define AIWORKER_H
#include "WorldWorker.h"
#include "Logics/CreatureLogic.h"


class AIWorker: public WorldWorker
{
public:
    AIWorker();
    virtual ~AIWorker();
    void work ( World *world ) override;

private:
    CreatureLogic *creaturelogic;

};

#endif // AIWORKER_H
