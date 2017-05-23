

#ifndef MAPGENERATION_H
#define MAPGENERATION_H
#include "../World.h"
class MapGeneration
{
public:
    MapGeneration();
    ~MapGeneration();
    void makeNoise(World *world);
};

#endif // MAPGENERATION_H
