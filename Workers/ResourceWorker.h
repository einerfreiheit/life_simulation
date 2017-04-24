#ifndef WORKERS_RESOURCEWORKER_H_
#define WORKERS_RESOURCEWORKER_H_
#include "WorldWorker.h"

class ResourceWorker: public WorldWorker
{
public:
    ResourceWorker();
    virtual ~ResourceWorker();
    void work ( World *world ) override;
    static inline int getRandom (int border );
   
    
private:
    double gainPerCell;
    int cellNumber;
    double cellGain;
    int height;
    int width;
    double amountOFWater=1000;

};

#endif
