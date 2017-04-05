#include "WorkerFactory.h"
#include "../Workers/AIWorker.h"
#include "../Workers/VisualWorker.h"
#include "Workers/WorldWorker.h"
#include "Workers/AIWorker.h"
#include "Workers/VisualWorker.h"
#include "Workers/WaiterWorker.h"
#include "Workers/CreatureSpawnWorker.h"
#include "Workers/VideoWriterWorker.h"
#include "Workers/CreatureRemoveWorker.h"
#include "Workers/ResourceWorker.h"
#include "Workers/CreatureActionWorker.h"//@ мне больше нравятся нормальные относительные пути


void WorkerFactory::build(std::vector<WorldWorker*>&workers) {
	addWorker<ResourceWorker>(workers,SimulationData::getInst()->useResourceWorker);
	addWorker <AIWorker> (workers);
	addWorker<CreatureActionWorker>(workers,SimulationData::getInst()->useCreatureActionWorker);
	addWorker <CreatureSpawnWorker>(workers,SimulationData::getInst()->useCreatureSpawnWorker);
	addWorker <CreatureRemoveWorker>(workers,SimulationData::getInst()->useCreatureRemoveWorker);
	addWorker<VisualWorker>(workers, SimulationData::getInst()->useVisualWorker);
	addWorker <VideoWriterWorker>(workers,SimulationData::getInst()->useVideoWriterWorker);

	addWorker <WaiterWorker>(workers,SimulationData::getInst()->useWaiterWorker);


}

