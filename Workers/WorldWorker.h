#ifndef WORLDWORKER_H
#define WORLDWORKER_H
#include "../World.h"
#include "SimulationData.h"

class WorldWorker
{
public:
    virtual void work(World *world) = 0;
    
    std::string getName() const;
    bool isAvailable=true;


protected:

    std::string name;
    double workerParameter=-1;

};

#endif // WORLDWORKER_H
