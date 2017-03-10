#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
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

	factory.build(new AIWorker);
	factory.build(new CreatureRemoveWorker);
	factory.build(new CreatureSpawnWorker);
	factory.build(new ResourceWorker);
	factory.build(new VideoWriterWorker);
	factory.build(new VisualWorker);
	factory.build(new WaiterWorker);

}

void SimulationRunner::run() {
	while (true) {
		for (WorldWorker *worker : factory.workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);

		}

	}
}
