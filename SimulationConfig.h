#ifndef SIMULATIONCONFIG_H
#define SIMULATIONCONFIG_H

#include "SimpleConfiguration.h"

class SimulationConfig : public SimpleConfiguration
{
public:
    int mapHeightToSet;
    int mapWidthToSet;
    int timeToWait;
    double gainResourcePerCell;
    double energyFromFood;
    double creatureOneBait;
    double energyToMove;
    bool useAIWorker;
    bool useCreatureRemoveWorker;
    bool useCreatureSpawnWorker;
    bool useResourceWorker;
    bool useVideoWriterWorker;
    bool useVisualWorker;
    bool useWaiterWorker;
    bool useCreatureActionWorker;
protected:
    void addParams() override;
};

#endif // SIMULATIONCONFIG_H
