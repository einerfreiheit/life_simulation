#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Factories/HeightsBuilder.h"

SimulationRunner::SimulationRunner() {
	init();

}

SimulationRunner::~SimulationRunner() {

}

void SimulationRunner::init() {
	srand(7 * clock() + time(NULL));
	world = new World(SimulationData::getInst()->mapHeightToSet,
			SimulationData::getInst()->mapWidthToSet);

	HeightsBuilder heights(world);

	heights.DiamondSquare(SimulationData::getInst()->scale);

	heights.getDepth(world->maxH, world->minH);

}

void SimulationRunner::run() {
	WorkerFactory::build(workers);

	while (true) {

		for (WorldWorker *worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);

		}

	}
}
