#include <iostream>
#include "ResourceFactory.h"
#include "../SimulationData.h"

void ResourceFactory::addWater ( World* world ) {
    int height =world->mapHeight;
    int width =world->mapWidth;
    for ( int y=0; y<height; y++ ) {
        for ( int x=0; x<width; x++ ) {
            if ( world->map[y][x].cellHeight<0 ) {
                world->map[y][x].water=SimulationData::getInst()->allWaterAmount/ ( height*width );




                }

            }
        }

    }
