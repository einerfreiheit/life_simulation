#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
#include <iostream>
#include "Factories/WorkerFactory.h"
#include "Factories/WorldBuilder.h"

SimulationRunner::SimulationRunner() {
	srand(7 * clock() + time( NULL));
	world = WorldBuilder::buidWorld();
	//world->map[0][0].water=10000;
}

SimulationRunner::~SimulationRunner() {
}

void SimulationRunner::run() {
	WorkerFactory::build(world, workers);
	while (true) {
		for (auto worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);
		}
	}
}
