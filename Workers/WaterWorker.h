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
	float soilWater = 0.0;
	float transmitterWaterLevel = 0.0;
	float recieverWaterLevel = 0.0;
	float movableWater = 0.0;
	float waterToMove = 0.0;
	float bufferedWaterLevel = 0.0;
	bool setTransmitterAndReciverPointers(World *world, int y1, int x1, int y2, int x2);
	void flow();

};

#endif
