#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_
#include "World.h"
#include "SimpleConfiguration.h"

class SimulationData: public SimpleConfiguration
{
public:
    static const SimulationData *getInst() {
        static SimulationData *inst = nullptr;
        if ( !inst ) {
            inst = new SimulationData;
        }
        return inst;
    }
    int firstStepDecrease;
    float cornerHeight;
    float smooth;
    float scale;
    int mapHeightToSet;
    int mapWidthToSet;
    int timeToWait;
    double gainResourcePerCell;
    double energyFromFood;
    double creatureOneBait;
    double energyToMove;
    double fissionLoss;
    double fissionThreshold;
    bool displayOutput;
    bool videoRecord;
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
private:
    SimulationData();
    SimulationData ( const SimulationData& root );
    SimulationData& operator= ( const SimulationData& );
};

#endif
