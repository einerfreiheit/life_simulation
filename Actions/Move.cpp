#include "Move.h"
#include <cmath>
#include <iostream>
Move::Move ( int moveToY, int moveToX ) {
    this->dx = moveToX;
    this->dy = moveToY;
    type=AT_MOVE;
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


bool Move::canMove ( World *world, Creature &creature, int nextX, int nextY, double &requariedEnergy ) {
    if ( checkBorder ( world,nextX,nextY ) ) {
        int currentX=creature.getPosX();
        int currentY=creature.getPosY();
        double currentHeight=world->map[currentY][currentX].cellHeight;
        double nextHeight = world->map[nextY][nextX].cellHeight;
        double energyToClimb= creature.phenotype->energyToClimb;
        double energyToMove = creature.phenotype->energyToMove;
        requariedEnergy=energyRequaried ( currentHeight,nextHeight,energyToClimb,energyToMove );
        if ( requariedEnergy<=creature.getEnergy() ) {
            return true;
            }
        else {
            return false;
            }
        }
    else {
        return false;
        }
    }


void Move::act ( World *world, Creature &creature ) {

    double energyReq=0;
    if ( canMove ( world, creature,dx,dy,energyReq ) ) {
        creature.setEnergy ( creature.getEnergy()-energyReq );
        creature.setPosX ( dx );
        creature.setPosY ( dy );

        }
    }
Move::~Move() {

    }

