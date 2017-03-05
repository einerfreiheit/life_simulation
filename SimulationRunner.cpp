#include "SimulationRunner.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/VideoWriterWorker.h"
#include "Workers/CreatureRemoveWorker.h"
#include <iostream>
#include <time.h>
#include "Workers/ResourceWorker.h"

SimulationRunner::SimulationRunner() {

}

SimulationRunner::~SimulationRunner() {

}

void SimulationRunner::init() {
	srand(7 * clock() + time(NULL));
	world = new World();

	workers.push_back(new VideoWriterWorker(world));
	workers.push_back(new AIWorker);
	workers.push_back(new CreatureSpawnWorker());
	workers.push_back(new CreatureRemoveWorker());

	ResourceWorker *resourceWorker = new ResourceWorker;
	resourceWorker->setGainResource(2.0);
	resourceWorker->setNuberOfCellToGainResources(4);
	workers.push_back(resourceWorker);

	workers.push_back(new VisualWorker);
	WaiterWorker *waiterWorker = new WaiterWorker;
	waiterWorker->setWaitingTime(10000);

	workers.push_back(waiterWorker);

}

void SimulationRunner::run() {

	while (true) {
		for (WorldWorker *worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);

		}

	}
}
