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

    int mapHeight;//@ инфа об этих двух полях содержится уже в map
    int mapWidth;//@
    float heightsRange;//@ ни нужна
    float maxHeight;//@ можно хранить в классе для визуализациии
    float minHeight;//@ и это тоже

    std::vector<std::vector<Cell> > map;
    std::vector<CreaturePtr> creatures;
private:
    void init();

};

#endif
