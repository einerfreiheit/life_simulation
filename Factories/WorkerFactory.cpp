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


void WorkerFactory::build(std::vector<WorldWorker*>&workers) {
	addWorker <AIWorker> (workers);
	addWorker<VisualWorker>(workers, SimulationData::getInst()->useVisualWorker);
	addWorker<ResourceWorker>(workers,SimulationData::getInst()->useResourceWorker);
	addWorker <CreatureSpawnWorker>(workers,SimulationData::getInst()->useCreatureSpawnWorker);
	addWorker <CreatureRemoveWorker>(workers,SimulationData::getInst()->useCreatureRemoveWorker);
	addWorker <VideoWriterWorker>(workers,SimulationData::getInst()->useVideoWriterWorker);
	addWorker <WaiterWorker>(workers,SimulationData::getInst()->useWaiterWorker);


}

