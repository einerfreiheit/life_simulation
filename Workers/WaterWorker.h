#ifndef WATERWORKER_H
#define WATERWORKER_H

#include "WorldWorker.h"

class WaterWorker: public WorldWorker {
public:
	WaterWorker();
	virtual ~WaterWorker();
	void work(World *world) override;
private:
	Cell *transmitter = NULL;
	Cell *receiver = NULL;
	Cell *bufferPointer = NULL;
	double soilWater = 0.0;
	double transmitterWaterLevel = 0.0;
	double recieverWaterLevel = 0.0;
	double movableWater = 0.0;
	double waterToMove = 0.0;
	double bufferedWaterLevel = 0.0;
	bool setTransmitterAndReciverPointers(World *world, int y1, int x1, int y2, int x2);
	void flow();

};

#endif
