#ifndef DIAMONDSQUARE_H
#define DIAMONDSQUARE_H

#include "../World.h"
class DiamondSquare
{
public:
    DiamondSquare(World*world);
    ~DiamondSquare();
    
private:
    void diamondSquare ( World*world, float scale );
    void init ( World *world );
    void diamondStep ( World* world, int y, int x, float scale );
    void squareStep ( World *world, int y, int x, float scale );
    float rangedRandom();
    void setDepth ( World *world );
    bool  checkIndex ( int index,int size );
    int step;
};

#endif
