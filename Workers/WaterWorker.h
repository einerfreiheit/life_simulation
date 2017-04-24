#include "WorldWorker.h"

#ifndef WATERWORKER_H
#define WATERWORKER_H

class WaterWorker :public WorldWorker
{
public:
    WaterWorker();
    ~WaterWorker();
    void work (World * world) override;
    bool canFlow(double currentHeight, double nextHeight, double currentWater, double nextCellWater, double soiledWater, double waterQuant);;
    void flow(double &currentCellWater, double &nextCellWater,double curentHeight, double nextHeight, double waterQuant);
};

#endif // WATERWORKER_H
