#include "SimulationRunner.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/VideoCapWorker.h"
#include "Workers/ResWorker.h"
#include "Workers/CreatureSpawnWorker.h"
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
    CreatureSpawnWorker spawner;//@ для изначального спауна червей лучше сделать инициализатор мира, а не воркер; воркер больше подойдёт для спауна червей в процессе жизни мира
    spawner.work(world);

    workers.push_back(new VisualWorker);
    workers.push_back(new VideoCapWorker(world));
    workers.push_back(new AIWorker);
    workers.push_back(new ResWorker);
    workers.push_back(new WaiterWorker(100000));//@ подумай над порядком воркеров: логичнее сначала произвести над миром все изменения, а потом уже нарисовать всё и отобразить


}

void SimulationRunner::run(){

    while (true){
        for (WorldWorker *worker: workers){
            std::cout << worker->getName() << std::endl;
            worker->work(world);


        }

    }
}
