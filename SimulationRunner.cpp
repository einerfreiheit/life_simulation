#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Factories/HeightsBuilder.h"
#include "Factories/ResourceFactory.h"
#include "Factories/CreatureBuilder.h"

SimulationRunner::SimulationRunner() {
	srand(7 * clock() + time( NULL));
	world = new World(SimulationData::getInst()->mapHeightToSet, SimulationData::getInst()->mapWidthToSet);

	HeightsBuilder::build(world);
	ResourceFactory::addWater(world);
	world->creatures.push_back(CreatureBuilder::build(world, 1, 1));
}

SimulationRunner::~SimulationRunner() {
	delete world;
}

void SimulationRunner::run() {
	WorkerFactory::build(workers);

	while (true) {
		for (auto worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);
		}
	}
}
