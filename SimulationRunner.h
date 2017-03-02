#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H

#include "Workers/WorldWorker.h"

class SimulationRunner
{
public:
    SimulationRunner();
    ~SimulationRunner();
    
    void init();
    void run();
private:
    std::vector<WorldWorker *> workers;
    World *world;


};

#endif // SIMULATIONRUNNER_H
