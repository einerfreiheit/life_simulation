
#include "ResourseFactory.h"

void ResourseFactory::addWater ( World* world ) {
    int height =world->mapHeight;
    int width =world->mapWidth;
    for ( int y=0; y<height; y++ ) {
        for ( int x=0; x<width; x++ ) {
            if ( world->map[y][x].cellHeight<0 ) {
                world->map[y][x].water=-world->map[y][x].cellHeight;




                }

            }
        }

    }