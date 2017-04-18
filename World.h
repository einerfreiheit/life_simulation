#ifndef WORLD_H
#define WORLD_H
#include "Factories/CreatureBuilder.h"
#include "CommonIncludes.h"
#include <vector>
#include "Cell.h"
#include "Creature.h"
class World
{
public:
    World ( int mapHeightToSet,  int mapWidthToSet );
    ~World();

    int mapHeight;
    int mapWidth;
    float heightsRange;

    std::vector<std::vector<Cell> > map;
    std::vector<Creature *> creatures;
private:
    void init();

};

#endif
