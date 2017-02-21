#ifndef WORLD_H
#define WORLD_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include "cell.h"
#include "worm.h"

class World
{
public:
    World();
    ~World();
    void step();
    int getHeight() const;
    int getWidth() const;
    void init();
    void getVis();
    void getWorm();
    int const mapHeight = 10;
    int const mapWidth = 10;
    int const worm_map_size = 2;
    std::vector<std::vector<cell> > map;
    std::vector<worm> worm_map;
};

#endif // WORLD_H
