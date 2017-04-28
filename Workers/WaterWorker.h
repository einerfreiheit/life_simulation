#include "WorldWorker.h"

#ifndef WATERWORKER_H
#define WATERWORKER_H

class WaterWorker :public WorldWorker
{
public:
    WaterWorker();
    virtual ~WaterWorker();
    void work ( World * world ) override;
private:
    bool canFlow ( double currentHeight, double nextHeight, double currentWater, double nextCellWater, double soildWater, double waterQuant );
    void flow ( double &currentCellWater, double &nextCellWater,double curentHeight, double nextHeight, double waterQuant );
    double soilWater;

};

#endif // WATERWORKER_H
