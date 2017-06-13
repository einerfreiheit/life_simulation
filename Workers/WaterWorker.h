#ifndef WATERWORKER_H
#define WATERWORKER_H

#include "WorldWorker.h"

class WaterWorker: public WorldWorker {
public:
	WaterWorker();
	virtual ~WaterWorker();
	void work(World *world) override;
private:
	void flow(Cell *current, Cell *next, double waterQuant);
	double soilWater;

};

#endif
