#include "WaterWorker.h"
#include "../SimulationData.h"
#include <cmath>
#include <iostream>
#include <vector>

WaterWorker::WaterWorker() {
	this->name = "WaterWorker";
	soilWater = SimulationData::getInst()->soilWater;
}

void WaterWorker::flow(World *world, int y1, int x1, int y2, int x2) {
	if (!canFlow(world, y1, x1, y2, x2)) {
		return;
	}
	waterLevelsDelta = transmitterWaterLevel - recieverWaterLevel;
	movableWater = transmitter->water - soilWater;
	waterToMove = std::min(waterLevelsDelta / 2, movableWater);
	transmitter->water -= waterToMove;
	receiver->water += waterToMove;
}

void WaterWorker::work(World* world) {
	if (isRowsWave) {
		for (int y = 0; y < world->map.size() - 1; y++) {
			for (int x = 0; x < world->map[0].size(); x++) {
				flow(world, y, x, y + 1, x);

			}
		}
		isRowsWave = false;
		return;
	}
	for (int x = 0; x < world->map[0].size() - 1; x++) {
		for (int y = 0; y < world->map.size(); y++) {
			flow(world, y, x, y, x + 1);

		}
	}

}

bool WaterWorker::canFlow(World *world, int y1, int x1, int y2, int x2) {
	firstCell = world->getCell(y1, x1);
	secondCell = world->getCell(y2, x2);
	if (!firstCell || !secondCell) {
		return false;
	}

	firstCellWaterLevel = firstCell->height + firstCell->water;
	secondCellWaterLevel = secondCell->water + secondCell->height;
	if (firstCellWaterLevel > secondCellWaterLevel && firstCell->water > soilWater) {
		transmitter = firstCell;
		receiver = secondCell;
		transmitterWaterLevel = firstCellWaterLevel;
		recieverWaterLevel = secondCellWaterLevel;
		return true;
	}
	if (secondCellWaterLevel > firstCellWaterLevel && secondCell->water > soilWater) {
		transmitter = secondCell;
		receiver = firstCell;
		transmitterWaterLevel = secondCellWaterLevel;
		recieverWaterLevel = firstCellWaterLevel;
		return true;
	}
	return false;

}
WaterWorker::~WaterWorker() {
}

