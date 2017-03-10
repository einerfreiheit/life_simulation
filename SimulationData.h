#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_
#include "World.h"


class SimulationData {
public:
	static const SimulationData *getInst() {
		static SimulationData *inst;
		if (!inst)
			inst = new SimulationData;
		return inst;
	}
	World * world;

	int mapHeightToSet;
	int mapWidthToSet;
	int timeToWait;
	double gainResourcePerCell;
	bool AIWorkerIsAvailable ;
	bool CreatureRemoveWorkerIsAvailable;
	bool CreatureSpawnWorkerIsAvailable;
	bool ResourceWorkerIsAvailable;
	bool VideoWriterWorkerIsAvailable;
	bool VisualWorkerIsAvailable ;
	bool WaiterWorkerIsAvailable;

private:
	void readConfigParameters();
	SimulationData();
	SimulationData(const SimulationData& root);
	SimulationData& operator=(const SimulationData&);
};

#endif
