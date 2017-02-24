#include "SimulationRunner.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/VideoCapWorker.h"
#include "Workers/ResWorker.h"
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
    workers.push_back(new VideoCapWorker(world));
    workers.push_back(new AIWorker);
    workers.push_back(new ResWorker);
    workers.push_back(new WaiterWorker(4000));

}

void SimulationRunner::run(){

    while (true){
        for (WorldWorker *worker: workers){
            std::cout << worker->getName() << std::endl;
            worker->work(world);


        }

    }
}
