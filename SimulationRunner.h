#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H
#include "SimulationRunner.h"
#include "Workers/WorldWorker.h"
#include "Factories/WorkerFactory.h"
#include "SimulationData.h"
#include "Workers/WorldWorker.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/VideoWriterWorker.h"
#include "Workers/CreatureRemoveWorker.h"
#include <iostream>
#include <time.h>
#include "Workers/ResourceWorker.h"
#include "SimulationData.h"
#include <cstdlib>
class SimulationRunner
{
public:
    SimulationRunner();
    ~SimulationRunner();
    std::vector<WorldWorker *> workers  {10};
	WorkerFactory factory;


    void init();
    void run();
private:
    World *world;


};

#endif // SIMULATIONRUNNER_H
