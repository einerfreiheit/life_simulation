#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H
#include "Workers/WorldWorker.h"
#include "Factories/WorkerFactory.h"
#include "SimulationData.h"
#include "Workers/WorldWorker.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/VideoWriterWorker.h" //@ все эти инклуды конкретных воркеров должны сидеть внутри .cpp файла фабрики
#include "Workers/CreatureRemoveWorker.h" //@ суть фабрики как раз в том, чтобы скрыть и упростить работу с конкретными воркерами
#include <iostream>
#include "Workers/ResourceWorker.h"
#include <cstdlib>
class SimulationRunner {
public:
	SimulationRunner();
	~SimulationRunner();
	std::vector<WorldWorker *> workers;
	WorkerFactory factory;

	void init();
	void run();
private:
	World *world;

};

#endif // SIMULATIONRUNNER_H
