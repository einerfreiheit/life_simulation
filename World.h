#ifndef WORLD_H
#define WORLD_H
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
    float maxHeight;
    float minHeight;

    std::vector<std::vector<Cell> > map;
    std::vector<CreaturePtr> creatures;
private:
    void init();

};

#endif
