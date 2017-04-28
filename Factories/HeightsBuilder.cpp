#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/DiamondSquare.h"

void HeightsBuilder::setDepth ( World*world ) {

    float maxH = 0;
    float minH = 0;
    float cellHeight = 0;
    for ( int i = 0; i < world->mapWidth; i++ ) {
        for ( int j = 0; j < world->mapHeight; j++ ) {
            cellHeight = world->map[j][i].cellHeight;
            if ( cellHeight > maxH ) {
                maxH = cellHeight;
                }
            if ( cellHeight < minH ) {
                minH = cellHeight;
                }
            }
        }
    world->heightsRange = maxH - minH;
    world->maxHeight=maxH;
    world->minHeight=minH;
    }

void HeightsBuilder::build ( World* world ) {
    DiamondSquare diamondSquare ( world );
    HeightsBuilder::setDepth ( world );
    }
