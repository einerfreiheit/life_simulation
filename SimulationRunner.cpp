#include "SimulationRunner.h"

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
	WorkerFactory factory;
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
