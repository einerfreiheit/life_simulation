#include "WaterWorker.h"
#include "../SimulationData.h"
#include <cmath>
#include <iostream>
WaterWorker::WaterWorker() {
    this->name="WaterWorker";
    soilWater=SimulationData::getInst()->soilWater;


    }


void WaterWorker::flow ( Cell &current, Cell &next, double waterQuant ) {

    double waterLevelCurrent=current.cellHeight+current.water;
    double waterLevelNext=next.cellHeight+next.water;
    
    if ( std::abs ( waterLevelCurrent-waterLevelNext ) >waterQuant ) {
        if ( ( current.water>soilWater ) && ( waterLevelCurrent>waterLevelNext ) ) {
            current.water-=waterQuant;
            next.water+=waterQuant;

            }
        if ( ( next.water>soilWater ) && ( waterLevelNext>waterLevelCurrent ) ) {
            current.water+=waterQuant;
            next.water-=waterQuant;
            }
        }



    }




void WaterWorker::work ( World* world ) {
    double waterQuant=soilWater/2;
    int height =world->mapHeight;
    int width =world->mapWidth;
    for ( int y=0; y<height-1; y++ ) {
        for ( int x=0; x<width-1; x++ ) {
            Cell &current = world->map[y][x];
            Cell &right = world->map[y][x+1];
            Cell &diag = world->map[y+1][x+1];
            Cell& down = world->map[y+1][x];

            flow ( current,right,waterQuant );
            flow ( current,diag,waterQuant );
            flow ( current,down,waterQuant );




            }
        }
    }

WaterWorker::~WaterWorker() {

    }
