#include "SimulationRunner.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include <iostream>


SimulationRunner::SimulationRunner()
{

}

SimulationRunner::~SimulationRunner()
{

}

void SimulationRunner::init(){
    world = new World();
    workers.push_back(new VisualWorker);
    workers.push_back(new AIWorker);
    workers.push_back(new WaiterWorker(10000));

}

void SimulationRunner::run(){
    while (true){
        for (WorldWorker *worker: workers){
            std::cout << worker->getName() << std::endl;
            worker->work(world);


        }

    }
}
