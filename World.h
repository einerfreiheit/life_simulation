#ifndef WORLD_H
#define WORLD_H
#include "CommonIncludes.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include "Cell.h"
#include "Creature.h"

class World
{
public:
    World();
    ~World();
    cv::Mat visualization;
    int getHeight() const;
    int getWidth() const;
    void init();
    int const mapHeight = 30;
    int const mapWidth = 30;
    std::vector<std::vector<Cell> > map;
    std::vector<Creature *> creatures;//@ worm_map - плохое название, потому что это совсем не map
};

#endif // WORLD_H
