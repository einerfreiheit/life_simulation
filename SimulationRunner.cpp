#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Factories/HeightsBuilder.h"
#include "Factories/ResourseFactory.h"

SimulationRunner::SimulationRunner() {
    srand ( 7 * clock() + time ( NULL ) );
    world = new World ( SimulationData::getInst()->mapHeightToSet,
                        SimulationData::getInst()->mapWidthToSet );

    HeightsBuilder::build(world);
    ResourseFactory::addWater(world);
    
    }

SimulationRunner::~SimulationRunner() {
    delete world;
    }

void SimulationRunner::run() {
    WorkerFactory::build ( workers );

    while ( true ) {

        for ( WorldWorker *worker : workers ) {
            std::cout << worker->getName() << std::endl;
            worker->work ( world );

            }

        }
    }
