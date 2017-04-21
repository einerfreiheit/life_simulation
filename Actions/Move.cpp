#include "Move.h"
#include <cmath>
Move::Move ( int moveToY, int moveToX ) {
    this->dx = moveToX;
    this->dy = moveToY;
    type=AT_MOVE;
    }

bool Move::canMove ( World *world, int nextX, int nextY, double energyRequaried, double creatureEnergy ) {

    int borderY = world->mapHeight;
    int borderX = world->mapWidth;
    if ( nextX < 0 || nextX >= borderX ) {
        return false;
        }
    else {
        if ( nextY < 0 || nextY >= borderY || creatureEnergy<energyRequaried ) {
            return false;
            }
        else {

            return true;
            }

        }

    }

double Move::getPath ( double height ) {

      return sqrt(1+pow(height,2));
    }

  
double Move::energyToMove ( World *world, Creature & creature ) {
    int currentX = creature.getPosX();
    int currentY = creature.getPosY();
    int nextX = dx;
    int nextY = dy;
    double heightDifference =world->map[currentY][currentX].cellHeight-world->map[nextY][nextX].cellHeight;
    double requariedEnergy=0;
    if ( heightDifference>=0 ) {
        requariedEnergy=creature.getPhenotype()->energyToMove* (getPath(heightDifference) );
        }
    else {

        requariedEnergy=creature.getPhenotype()->energyToMove* getPath(heightDifference) *creature.energy/100;

        }
    return requariedEnergy;

    }

void Move::act ( World *world, Creature &creature ) {

    double energyReq= energyToMove ( world,creature );
    if ( canMove ( world, dx, dy, energyReq, creature.getEnergy() ) ) {
        creature.energy = creature.energy -energyReq;
        creature.setPosX ( dx );
        creature.setPosY ( dy );

        }

    }
Move::~Move() {

    }

