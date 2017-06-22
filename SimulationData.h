#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_

#include "World.h"
#include "SimpleConfiguration.h"
#include <string>

class SimulationData: public SimpleConfiguration {
public:
	static const SimulationData *getInst() {
		static SimulationData *inst = nullptr;
		if (!inst) {
			inst = new SimulationData;
		}
		return inst;
	}
	std::string outputPath;
	int mapHeightToSet;
	int mapWidthToSet;

	double firstLayerFrequency;

	bool displayOutput;
	bool videoRecord;
	bool useAIWorker;
	bool useCreatureRemoveWorker;
	bool useCreatureSpawnWorker;
	bool useResourceWorker;
	bool useVideoWriterWorker;
	bool useVisualWorker;
	bool useWaiterWorker;
	bool useCreatureActionWorker;
	bool useWaterWorker;

	int timeToWait;

	double soilWater;
	double waterPerCell;
	double foodGainPerCell;
	double gainResourcePerCell;

	double energyFromFood;
	double creatureOneBait;
	double energyToMove;
	double fissionLoss;
	double fissionThreshold;
	int numberOfMitoseCrossingOver;
	double creatureHealthPoints;
	double creatureAttackPower;

protected:
	void addParams() override;
private:
	SimulationData();
	SimulationData(const SimulationData& root);
	SimulationData& operator=(const SimulationData&);
};

#endif
