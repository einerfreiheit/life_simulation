#include "WaterWorker.h"
#include "../SimulationData.h"

WaterWorker::WaterWorker() {
    this->name="WaterWorker";
    soilWater=SimulationData::getInst()->soilWater;


    }
bool WaterWorker::canFlow ( double currentHeight, double nextHeight, double currentWater, double nextCellWater, double soilWater, double waterQuant ) {
    double sumOfWater = currentWater+nextCellWater;
    double waterLevelInCurrentCell=currentHeight+currentWater;
    double waterLevelInNextCell=nextCellWater+nextHeight;
    return ( ( sumOfWater>2*soilWater ) && ( ( waterLevelInCurrentCell-waterLevelInNextCell > waterQuant ) || ( waterLevelInNextCell-waterLevelInCurrentCell > waterQuant ) ) );
    }

void WaterWorker::flow ( double& currentCellWater, double& nextCellWater, double curentHeight, double nextHeight, double waterQuant ) {
    if ( currentCellWater+curentHeight>nextCellWater+nextHeight ) {
        currentCellWater-=waterQuant;
        nextCellWater+=waterQuant;

        }
    else {
        currentCellWater+=waterQuant;
        nextCellWater-=waterQuant;


        }

    }




void WaterWorker::work ( World* world ) {
    double waterQuant=0.01;
    soilWater=SimulationData::getInst()->soilWater;

    int height =world->mapHeight;
    int width =world->mapWidth;
    for ( int y=0; y<height-1; y++ ) {
        for ( int x=0; x<width-1; x++ ) {
            double currentHeight=world->map[y][x].cellHeight;
            double &currentWater = world->map[y][x].water;

            double rightCellHeight = world->map[y][x+1].cellHeight;
            double &rightCellWater=world->map[y][x+1].water;

            double downCellHeight = world->map[y+1][x].cellHeight;
            double &downCellWater=world->map[y+1][x].water;

            if ( canFlow ( currentHeight,rightCellHeight,currentWater,rightCellWater,soilWater,waterQuant ) ) {
                flow ( currentWater,rightCellWater,currentHeight,rightCellHeight,waterQuant );


                }
            if ( canFlow ( currentHeight,downCellHeight,currentWater,downCellWater,soilWater,waterQuant ) ) {
                flow ( currentWater,downCellWater,currentHeight,downCellHeight,waterQuant );


                }


            }
        }
    }

WaterWorker::~WaterWorker() {

    }
