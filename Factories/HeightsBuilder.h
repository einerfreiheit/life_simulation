
#ifndef HEIGHTSBUILDER_H
#define HEIGHTSBUILDER_H
#include "../World.h"

class HeightsBuilder
{
public:
    HeightsBuilder();
    ~HeightsBuilder();
     void build ( World*world );
private:
    void diamondSquare ( World*world, float scale );
    void init ( World *world );
    void diamondStep ( World* world, int y, int x, float scale );
    void squareStep ( World *world, int y, int x, float scale );
    float rangedRandom();
    void setDepth ( World *world );
    int  wrapIndex ( int index,int size );
    int step;
};

#endif 

