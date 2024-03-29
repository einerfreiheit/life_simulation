#include "WaterWorker.h"
#include "../SimulationData.h"
#include <cmath>
#include <iostream>
#include <vector>

WaterWorker::WaterWorker() {
	this->name = "WaterWorker";
	soilWater = SimulationData::getInst()->soilWater;
}

void WaterWorker::flow() {
	movableWater = transmitter->water - soilWater;
	if (movableWater <= 0.0) {
		return;
	}
	waterToMove = std::min(0.5 * (transmitterWaterLevel - recieverWaterLevel), (double)movableWater);

	if (!transmitter->creatures.empty() && waterToMove>0.01){

		for (auto creature: transmitter->creatures){
			creature->x=receiver->x;
			creature->y=receiver->y;
		}
		std::vector<CreaturePtr> displacedCreatures = transmitter->creatures;
		receiver->creatures.insert(receiver->creatures.end(),displacedCreatures.begin(), displacedCreatures.end());
		transmitter->creatures.clear();
	}

	transmitter->water -= waterToMove;
	receiver->water += waterToMove;

}

void WaterWorker::work(World* world) {

	for (int y = 0; y < world->map.size() - 1; y++) {
		for (int x = 0; x < world->map[0].size(); x++) {
			if (setTransmitterAndReciverPointers(world, y, x, y + 1, x)){
			  flow();
			}

		}
	}

	for (int x = 0; x < world->map[0].size() - 1; x++) {
		for (int y = 0; y < world->map.size(); y++) {
			if (setTransmitterAndReciverPointers(world, y, x, y, x + 1)){
			  flow();
			}
		}
	}

}

WaterWorker::~WaterWorker() {
}

bool WaterWorker::setTransmitterAndReciverPointers(World *world, int y1, int x1, int y2, int x2) {

	transmitter = world->getCell(y1, x1);
	transmitterWaterLevel = transmitter->height + transmitter->water;
	bufferPointer = world->getCell(y2, x2);
	bufferedWaterLevel = bufferPointer->height + bufferPointer->water;
	if (std::abs(bufferedWaterLevel - transmitterWaterLevel)<0.0001) {
		return false;
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

	return true;
}
