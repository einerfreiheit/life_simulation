#include "SimulationRunner.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/ResourseWorker.h"
#include "Workers/VideoWriterWorker.h"
#include <iostream>
#include <time.h>

SimulationRunner::SimulationRunner()
{

}

SimulationRunner::~SimulationRunner()
{

}

void SimulationRunner::init(){
    srand(7*clock() + time(NULL));//@ добавил инициализацию генератора случайных чисел. Погугли про это
    world = new World();

    workers.push_back(new VideoWriterWorker(world));
    workers.push_back(new AIWorker);
    workers.push_back(new ResourseWorker);
    workers.push_back(new VisualWorker);
    workers.push_back(new WaiterWorker(10000));
    workers.push_back(new CreatureSpawnWorker);


}

void SimulationRunner::run(){

    while (true){
        for (WorldWorker *worker: workers){
            std::cout << worker->getName() << std::endl;
            worker->work(world);


        }

    }
}
