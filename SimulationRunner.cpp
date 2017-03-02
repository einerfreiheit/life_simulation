#include "SimulationRunner.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/ResourseWorker.h"
#include "Workers/VideoWriterWorker.h"
#include <iostream>
#include <time.h>

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

	ResourseWorker *resourseWorker = new ResourseWorker;
	resourseWorker->setGainResourse(2.0);
	resourseWorker->setNuberOfCellToGainResourses(4);
	workers.push_back(resourseWorker);

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
