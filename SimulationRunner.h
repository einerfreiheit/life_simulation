#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H
#include "Workers/WorldWorker.h"
#include "Factories/WorkerFactory.h"
#include "SimulationData.h"
class SimulationRunner {
public:
	SimulationRunner();
	~SimulationRunner();
	std::vector<WorldWorker *> workers;

	void init();
	void run();
private:
	World *world;

};

#endif
