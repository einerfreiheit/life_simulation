#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

HeightsBuilder::HeightsBuilder() {
    }
HeightsBuilder::~HeightsBuilder() {
    }

void HeightsBuilder::setDepth ( World*world ) {

    int maxH = 0;
    int minH = 0;
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
    }

void HeightsBuilder::build ( World* world ) {


    init ( world );
    diamondSquare ( world, SimulationData::getInst()->scale );
    setDepth ( world );

    }
void HeightsBuilder::init ( World*world ) {
    int mapHeight = world->mapHeight;
    int mapWidth = world->mapWidth;

    float cornerHeight = SimulationData::getInst()->cornerHeight;
    int firstStepDecrease = SimulationData::getInst()->firstStepDecrease;
    int lesserSide = std::min ( mapHeight, mapWidth );
    float rawStep = std::log2 ( lesserSide );

    if ( std::abs ( rawStep ) < 0.0001 ) {
        step = pow ( 2, ( int ) ( rawStep ) - 1 );

        }
    else {
        step = pow ( 2, ( int ) std::floor ( rawStep ) );

        }
    if ( step > 0 ) {
        for ( int y = 0; y < mapHeight; y += step ) {
            for ( int x = 0; x < mapWidth; x += step ) {
                world->map[y][x].cellHeight = cornerHeight;

                }
            }
        }
    int firstStepDecerease = SimulationData::getInst()->firstStepDecrease;
    if ( firstStepDecrease==1 || ( !firstStepDecerease & ( firstStepDecerease - 1 ) ) ) {
        step = step / firstStepDecrease;

        }
    else {
        throw std::runtime_error ( "firstStepDecrease must be 1 or power of 2 " );
        }
    if ( lesserSide<=1 ) {
        throw std::runtime_error ( "world's sides size must be greater than 1" );
        }
    }



void HeightsBuilder::diamondStep ( World *world, int y, int x, float range ) {
    Cell &cell = world->map[y][x];
    float sumOfHeights = 0;

    int leftPointX=wrapIndex ( x-step/2,world->mapWidth );
    int rightPointX=wrapIndex ( x+step/2,world->mapWidth );
    int upperPoint=wrapIndex ( y-step/2,world->mapHeight );
    int lowerPoint=wrapIndex ( y+step/2,world->mapHeight );


    sumOfHeights += world->map[y][leftPointX].cellHeight;
    sumOfHeights += world->map[y][rightPointX].cellHeight;
    sumOfHeights+=world->map[upperPoint][x].cellHeight;
    sumOfHeights+=world->map[lowerPoint][x].cellHeight;

    cell.cellHeight = sumOfHeights / 4 + range * rangedRandom();
    }

int  HeightsBuilder::wrapIndex ( int index, int size ) {
    return index<0 ? size - ( ( ~index ) +1 ) % size : index % size;;


    }
void HeightsBuilder::squareStep ( World *world, int y, int x, float scale ) {

    float sumOfHeights = world->map[y][x].cellHeight;
    sumOfHeights += world->map[y + step][x].cellHeight;
    sumOfHeights += world->map[y][x + step].cellHeight;
    sumOfHeights += world->map[y + step][x + step].cellHeight;
    world->map[y + step / 2][x + step / 2].cellHeight = ( sumOfHeights ) / 4
            + rangedRandom() * scale;

    }

void HeightsBuilder::diamondSquare ( World*world, float scale ) {
    if ( step < 2 ) {
        return;
        }
    int borderY = world->mapHeight - step;
    int borderX = world->mapWidth - step;

    for ( int i = 0; i < borderY; i += step )
        for ( int j = 0; j < borderX; j += step ) {
            squareStep ( world, i, j, scale );

            }

    borderY= world->mapHeight;
    borderX= world->mapWidth-step/2;
    for ( int i = 0; i < borderY; i += step ) {
        for ( int j = step / 2; j < borderX; j += step ) {
            diamondStep ( world, i, j, scale );
            }
        }
    borderY= world->mapHeight-step/2;
    borderX = world->mapWidth;
    for ( int i = step / 2; i < borderY; i += step ) {
        for ( int j = 0; j < borderX; j += step ) {

            diamondStep ( world, i, j, scale );

            }
        }

    step /= 2;
    scale /= SimulationData::getInst()->smooth;
    diamondSquare ( world, scale );

    }

float HeightsBuilder::rangedRandom() {
    return 2 * ( float ) rand() / RAND_MAX - 1;

    }
