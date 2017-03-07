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
#include "SimulationData.h"

SimulationRunner::SimulationRunner() {

}

SimulationRunner::~SimulationRunner() {

}

void SimulationRunner::init() {
	srand(7 * clock() + time(NULL));
	world = SimulationData::inst().world;
	workers.push_back(new VideoWriterWorker(world));
	workers.push_back(new AIWorker);
	workers.push_back(new CreatureSpawnWorker());
	workers.push_back(new CreatureRemoveWorker());

	ResourceWorker *resourceWorker = new ResourceWorker;
	resourceWorker->setAverageGainPerCell(SimulationData::inst().gainResource);
	workers.push_back(resourceWorker);

	workers.push_back(new VisualWorker);
	WaiterWorker *waiterWorker = new WaiterWorker;
	waiterWorker->setWaitingTime(SimulationData::inst().timeToWait);

	workers.push_back(waiterWorker);

}

void SimulationRunner::run() {

	while (true) {
		for (WorldWorker *worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);
		    std::cout<<SimulationData::inst().gainResource<<SimulationData::inst().height<<SimulationData::inst().width<<SimulationData::inst().timeToWait<<std::endl;


		}

	}
}
