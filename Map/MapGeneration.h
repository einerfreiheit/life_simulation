

#ifndef MAPGENERATION_H
#define MAPGENERATION_H
#include "../World.h"
class MapGeneration
{
public:
    MapGeneration();
    ~MapGeneration();
    void makeNoise(World *world);
private:
    void setKeyValues();
    float getValue(int y, int x, float frequency, float amplitude);
    float* keyValues = NULL;
    const int keySize = 256;
    unsigned int keyMask = keySize-1;
    float smooth(const float& value);
    float lerp( float f1, float f2, float possition);
    
    
};

#endif
