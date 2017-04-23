
#include "ResourseFactory.h"
double ResourseFactory::amountOfWater=100;

void ResourseFactory::addWater ( World* world ) {
    int height =world->mapHeight;
    int width =world->mapWidth;
    double waterPerCell=amountOfWater/ ( width*height );
    for ( int y=0; y<height; y++ ) {
        for ( int x=0; x<width; x++ ) {
            if ( world->map[y][x].cellHeight<0 ) {
                world->map[y][x].water=-world->map[y][x].cellHeight;




                }

            }
        }

    }