#include "SimulationRunner.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

#include "Workers/AIWorker.h"

SimulationRunner::SimulationRunner()
{

}

SimulationRunner::~SimulationRunner()
{

}

void SimulationRunner::init(){
    world = new World();
    workers.push_back(new AIWorker);
}

void SimulationRunner::run(){
    while (true){
        for (WorldWorker *worker: workers){
            std::cout << worker->getName() << std::endl;
            worker->work(world);
        }
        world->getVis();
        usleep(500000);
    }
}