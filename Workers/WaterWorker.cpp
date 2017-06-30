#include "WaterWorker.h"
#include "../SimulationData.h"
#include <cmath>
#include <iostream>
#include <vector>

WaterWorker::WaterWorker() {
	this->name = "WaterWorker";
	soilWater = SimulationData::getInst()->soilWater;
}

void WaterWorker::flow( bool &canFlow) {
	if (!canFlow) {
		return;
	}

	movableWater = transmitter->water - soilWater;
	if (movableWater <= 0.0) {
		return;
	}
	waterToMove = std::min(0.5 * (transmitterWaterLevel - recieverWaterLevel), movableWater);

	if (!transmitter->creaturesInCell.empty() && waterToMove>0.01){

		for (auto creature: transmitter->creaturesInCell){
			creature->x=receiver->xCoordinate;
			creature->y=receiver->yCoordinate;
		}
		std::vector<CreaturePtr> displacedCreatures = transmitter->creaturesInCell;
		receiver->creaturesInCell.insert(receiver->creaturesInCell.end(),displacedCreatures.begin(), displacedCreatures.end());
		transmitter->creaturesInCell.clear();
	}

	transmitter->water -= waterToMove;
	receiver->water += waterToMove;

}

void WaterWorker::work(World* world) {

	for (int y = 0; y < world->map.size() - 1; y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			setTransmitterAndReciverPointers(world, y, x, y + 1, x, canFlow);
			flow(canFlow);

		}
	}

	for (int x = 0; x < world->map[0].size() - 1; x++) {
		for (int y = 0; y < world->map.size(); y++) {
			setTransmitterAndReciverPointers(world, y, x, y, x + 1, canFlow);
			flow( canFlow);
		}
	}

}

WaterWorker::~WaterWorker() {
}

void WaterWorker::setTransmitterAndReciverPointers(World *world, int y1, int x1, int y2, int x2, bool &canFlow) {

	transmitter = world->getCell(y1, x1);
	transmitterWaterLevel = transmitter->height + transmitter->water;
	bufferPointer = world->getCell(y2, x2);
	bufferedWaterLevel = bufferPointer->height + bufferPointer->water;
	if (bufferedWaterLevel == transmitterWaterLevel) {
		canFlow = false;
		return;
	}
	if (transmitterWaterLevel > bufferedWaterLevel) {
		receiver = bufferPointer;
		recieverWaterLevel = bufferedWaterLevel;
	}
	else {
		receiver = transmitter;
		transmitter = bufferPointer;
		recieverWaterLevel = transmitterWaterLevel;
		transmitterWaterLevel = bufferedWaterLevel;

	}

	canFlow = true;

}
