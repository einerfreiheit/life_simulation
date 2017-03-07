#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_
#include "World.h"

class SimulationData {
public:
	static const SimulationData& inst() {
		static SimulationData theSingleInstance;
		return theSingleInstance;
	}
	int height;
	int width;
	int timeToWait;
	double gainResource;
	World * world;
	void setVariables();

private:
	SimulationData();
	SimulationData(const SimulationData& root);
	SimulationData& operator=(const SimulationData&);
};

#endif
