#ifndef WORKERS_HEIGHTSWORKER_H_
#define WORKERS_HEIGHTSWORKER_H_

#include "WorldWorker.h"

class HeightsWorker: public WorldWorker
{
public:
    HeightsWorker();
    virtual ~HeightsWorker();

    void work ( World*world ) override;

private:
    void diamondSquare ( World*world, float scale );
    void init ( World *world );
    void diamondStep ( World* world, int y, int x, float scale );
    void squareStep ( World *world, int y, int x, float scale );
    float rangedRandom();
    void setDepth ( World *world );
    //bool checkBorder(World *world,int y,int x);

    int  wrapIndex ( int index,int size );

    int step;


};

#endif
