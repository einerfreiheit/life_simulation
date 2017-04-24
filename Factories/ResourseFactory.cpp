#include <iostream>
#include "ResourseFactory.h"
 double ResourseFactory::range = 1;
void ResourseFactory::addWater ( World* world ) {
    int height =world->mapHeight;
    int width =world->mapWidth;
    for ( int y=0; y<height; y++ ) {
        for ( int x=0; x<width; x++ ) {
            if ( world->map[y][x].cellHeight<0 ) {
                world->map[y][x].water=ResourseFactory::range;
// 	      world->map[y][x].water=5;




                }

            }
        }

    }
