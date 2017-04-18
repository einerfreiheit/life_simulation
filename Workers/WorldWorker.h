#ifndef WORLDWORKER_H
#define WORLDWORKER_H
#include "../World.h"
#include "SimulationData.h"

class WorldWorker
{
public:
    virtual void work ( World *world ) = 0;
    std::string getName() const;
protected:

    std::string name;

};

#endif
