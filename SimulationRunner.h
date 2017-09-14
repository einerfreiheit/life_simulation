#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H

#include "Workers/WorldWorker.h"

class SimulationRunner {
public:
	SimulationRunner();
	~SimulationRunner();
	std::vector<WorldWorker *> workers;
	void run();
private:
	World *world =NULL;

};

#endif
