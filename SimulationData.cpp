#include "SimulationData.h"
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

SimulationData::SimulationData() {
	load("config.ini");

}
void SimulationData::addParams() {
	setSection("World");
	add<int>("height", mapHeightToSet, 5);
	add<int>("width", mapWidthToSet, 5);
	setSection("WorldHeights");
	add<int>("firstStepDecrease", firstStepDecrease, 1);
	add<float>("cornerHeight", cornerHeight, 0);
	add<float>("smooth", smooth, 2);
	add<float>("scale", scale, 10);

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

	setSection("WaitingTime");
	add<int>("timeToWait", timeToWait, 1000);

	setSection("Resources");
	add<double>("gainPerCell", gainResourcePerCell, 0.0);
	add<double>("allWaterAmount", allWaterAmount, 0);
	add<double>("soilWater", soilWater, 0.01);

	setSection("CreatureParameters");
	add<double>("creatureOneBait", creatureOneBait, 1.0);
	add<double>("energyToMove", energyToMove, 1.0);
	add<double>("energyFromFood", energyFromFood, 1.0);
	add<double>("fissionLoss", fissionLoss, 100);
	add<double>("fissionThreshold", fissionThreshold, 500);

	setSection("Output");
	add<std::string>("outputPath", outputPath, "./");
}
