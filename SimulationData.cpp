#include "SimulationData.h"
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

SimulationData::SimulationData() {
	load("config.ini");

}
void SimulationData::addParams() {
	setSection("World");
	add<int>("height", mapHeight, 5);
	add<int>("width", mapWidth, 5);
	setSection("WorldHeights");
	add<double>("firstLayerFrequency", firstLayerFrequency, 0.3);

	setSection("Workers");
	add<bool>("useAIWorker", useAIWorker, true);
	add<bool>("useCreatureActionWorker", useCreatureActionWorker, true);
	add<bool>("useCreatureRemoveWorker", useCreatureRemoveWorker, true);
	add<bool>("useCreatureSpawnWorker", useCreatureSpawnWorker, true);
	add<bool>("useResourceWorker", useResourceWorker, true);
	add<bool>("useVisualWorker", useVisualWorker, true);
	add<bool>("useVideoWriterWorker", useVideoWriterWorker, true);
	add<bool>("useWaiterWorker", useWaiterWorker, true);
	add<bool>("displayOutput", displayOutput, true);
	add<bool>("videoRecord", videoRecord, false);
	add<bool>("useWaterWorker", useWaterWorker, false);
	add<bool>("useOpenGLRenderWorker",useOpenGLRenderWorker,true);
	add <bool> ("useMetabolismWorker", useMetabolismWorker,true);
	setSection("WaitingTime");
	add<int>("timeToWait", timeToWait, 1000);

	setSection("Resources");
	add<double>("foodGainPerCell", foodGainPerCell, 0.0);
	add<double>("waterPerCell", waterPerCell, 0.0);
	add<double>("soilWater", soilWater, 0.01);

	setSection("CreatureParameters");
	add<double>("creatureOneBait", creatureOneBait, 1.0);
	add<double>("energyToMove", energyToMove, 1.0);
	add<double>("energyFromFood", energyFromFood, 1.0);
	add<double>("fissionLoss", fissionLoss, 100);
	add<double>("fissionThreshold", fissionThreshold, 500);
	add<int>("numberOfMitoseCrossingOver", numberOfMitoseCrossingOver,1);
	add<double>("creatureHealthPoints", creatureHealthPoints,100.0);
	add<double>("creatureAttackPower", creatureAttackPower,1.0);

	setSection("Output");
	add<std::string>("outputPath", outputPath, "./");
	add<bool> ("usePLY", usePLY, false);
}
