#ifndef AIWORKER_H
#define AIWORKER_H
#include "WorldWorker.h"
#include "Logics/SimpleLogics.h"


class AIWorker: public WorldWorker
{
public:
    AIWorker();
    virtual ~AIWorker();
    void work ( World *world ) override;

private:
    SimpleLogics *simple;
    

};

#endif // AIWORKER_H
