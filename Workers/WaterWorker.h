#ifndef WATERWORKER_H
#define WATERWORKER_H

#include "WorldWorker.h"

class WaterWorker: public WorldWorker {
public:
	WaterWorker();
	virtual ~WaterWorker();
	void work(World *world) override;
private:

	void flow(World *world, int y1, int x1, int y2, int x2);
	bool canFlow(World *world, int y1, int x1, int x2, int y2);
	double soilWater = 0.0;
	Cell *firstCell = NULL;
	Cell *secondCell = NULL;
	Cell *transmitter = NULL;
	Cell *receiver = NULL;
	double firstCellWaterLevel=0.0;
	double secondCellWaterLevel =0.0;
	double transmitterWaterLevel=0.0;
	double recieverWaterLevel =0.0;
	double movableWater=0.0;
	double waterLevelsDelta=0.0;
	double waterToMove = 0.0;
	bool isRowsWave = true;

};

#endif
