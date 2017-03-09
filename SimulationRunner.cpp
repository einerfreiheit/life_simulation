#include "SimulationRunner.h"
#include "Workers/WorldWorker.h"
#include "Factories/WorkerVectorFactory.h"
#include "SimulationRunner.h"
#include "SimulationData.h"
#include "Workers/WorldWorker.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/VideoWriterWorker.h"
#include "Workers/CreatureRemoveWorker.h"
#include "WorkerVectorFactory.h"
#include <iostream>
#include <time.h>
#include "Workers/ResourceWorker.h"
#include "SimulationData.h"
#include <cstdlib>
using namespace std;

SimulationRunner::SimulationRunner() {

}

SimulationRunner::~SimulationRunner() {

}

void SimulationRunner::init() {
	srand(7 * clock() + time(NULL));
	SimulationData::getInst();
	world = SimulationData::getInst()->world;

//	workers.push_back(new AIWorker);
//	workers.push_back(new VisualWorker);
	WorkerVectorFactory factory;
//	WorldWorker *worker= new AIWorker;
//	workers.push_back(worker);
		factory.build();
//	workers=factory.workers;

}

void SimulationRunner::run() {
	while (true) {
		for (WorldWorker *worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);

		}

	}
}
