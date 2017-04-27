#include "Move.h"
#include <cmath>
#include <iostream>
Move::Move ( ) {
    type=AT_MOVE;
    }

void Move::setXandY ( int x, int y ) {
    dx=x;
    dy=y;

    }

bool Move::checkBorder ( World* world, int nextX, int nextY ) {
    int borderY = world->mapHeight;
    int borderX = world->mapWidth;
    if ( nextX < 0 || nextX >= borderX ) {
        return false;
        }
    else {
        if ( nextY < 0 || nextY >= borderY ) {
            return false;
            }
        else {

            return true;
            }

        }

    }


double Move::energyRequaried ( double currentHeight, double nextHeight,double energyToClimb, double energyToMove ) {

    return currentHeight<nextHeight? ( nextHeight-currentHeight ) *energyToClimb + energyToMove : energyToMove;

    }





void Move::act ( World *world, CreaturePtr creature ) {

    double energyReq=0;
    if ( checkBorder ( world,dx,dy ) ) {
        int currentX=creature->getPosX();
        int currentY=creature->getPosY();

        int creatureId= creature->getId();
        double currentHeight=world->map[currentY][currentX].cellHeight;
        double nextHeight = world->map[dy][dx].cellHeight;
        double energyToClimb = creature->phenotype->energyToClimb;
        double energyToMove = creature->phenotype->energyToMove;
        energyReq=energyRequaried ( currentHeight,nextHeight,energyToClimb,energyToMove );


        if ( energyReq<=creature->getEnergy() ) {
            creature->setEnergy ( creature->getEnergy()-energyReq );
            creature->setPosX ( dx );
            creature->setPosY ( dy );

            Cell &currentCell=world->map[currentY][currentX];
            Cell &nextCell = world->map[dy][dx];
            int creaturesInCurrentCellSize=currentCell.creaturesInCell.size();
            if ( currentCell.creaturesInCell.size() >1 ) {
                for ( int i=0; i<creaturesInCurrentCellSize; i++ ) {
                    if ( creatureId==currentCell.creaturesInCell[i]->getId() ) {
                        nextCell.creaturesInCell.push_back ( currentCell.creaturesInCell[i] );
                        currentCell.creaturesInCell[i]= currentCell.creaturesInCell[creaturesInCurrentCellSize-1];
                        currentCell.creaturesInCell.resize ( creaturesInCurrentCellSize-1 );
                        break;

                        }


                    }
                }
            else {
                nextCell.creaturesInCell=currentCell.creaturesInCell;
                currentCell.creaturesInCell.resize ( 0 );

                }



            }
        else {
            return;
            }

        }
    else {
        return;
        }
    }
Move::~Move() {

    }

