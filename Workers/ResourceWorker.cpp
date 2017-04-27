#include "ResourceWorker.h"
#include <cmath>
#include <cstdlib>
ResourceWorker::ResourceWorker() {
    this->name = "ResourceWorker";
    this->gainPerCell = SimulationData::getInst()->gainResourcePerCell;
    height =SimulationData::getInst()->mapHeightToSet;
    width = SimulationData::getInst()->mapWidthToSet;
    cellNumber = ( int ) ( sqrt ( height * width ) );
    cellGain = height * width * gainPerCell / cellNumber;
    

    }

int ResourceWorker::getRandom ( int border ) {
    return (int )rand() % border;

    }


void ResourceWorker::work ( World *world ) {

    for ( int i = 0; i <= cellNumber; i++ ) {

        int rY=getRandom ( height );
        int rX=getRandom ( width );
        if ( world->map[ rY ][rX].food <= ( 100.0 - cellGain ) ) {
            world->map[rY][rX].food += cellGain;
            }

        }
    }
ResourceWorker::~ResourceWorker() {
    }

