#include "WorkerFactory.h"
#include "../SimulationData.h"
#include "../Workers/AIWorker.h"
#include "../Workers/CreatureActionWorker.h"
#include "../Workers/CreatureSpawnWorker.h"
#include "../Workers/CreatureRemoveWorker.h"
#include "../Workers/ResourceWorker.h"
#include "../Workers/VisualWorker.h"
#include "../Workers/WaiterWorker.h"
#include "../Workers/WaterWorker.h"
#include "../Workers/MetabolismWorker.h"
#include "../Workers/OpenGLRenderWorker.h"

void WorkerFactory::build(World *world, std::vector<WorldWorker*>&workers) {
	addWorker<AIWorker>(workers, SimulationData::getInst()->useAIWorker);
	addWorker<CreatureActionWorker>(workers, SimulationData::getInst()->useCreatureActionWorker);
	addWorker<CreatureSpawnWorker>(workers, SimulationData::getInst()->useCreatureSpawnWorker);
	addWorker<CreatureRemoveWorker>(workers, SimulationData::getInst()->useCreatureRemoveWorker);
	addWorker<ResourceWorker>(workers, SimulationData::getInst()->useResourceWorker);
	addWorker<VisualWorker>(world,workers, SimulationData::getInst()->useVisualWorker);
	addWorker<WaiterWorker>(workers, SimulationData::getInst()->useWaiterWorker);
	addWorker<WaterWorker>(workers, SimulationData::getInst()->useWaterWorker);
	addWorker<OpenGLRenderWorker>(world, workers, SimulationData::getInst()->useOpenGLRenderWorker);
	addWorker<MetabolismWorker>(workers, SimulationData::getInst()->useMetabolismWorker);

}

