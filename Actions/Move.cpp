#include "Move.h"

Move::Move ( int moveToY, int moveToX ) {
    this->dx = moveToX;
    this->dy = moveToY;
    type=AT_MOVE;
    }

bool Move::canMove ( World *world, int nextX, int nextY ) {

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
void Move::act ( World *world, Creature &creature ) {

    int currentX = creature.getPosX();
    int currentY = creature.getPosY();
    int nextX = dx;
    int nextY = dy;
    if ( canMove ( world, nextX, nextY ) ) {
        creature.energy = creature.energy
                          - SimulationData::getInst()->energyToMove;
        creature.setPosX ( nextX );
        creature.setPosY ( nextY );

        }

    }
Move::~Move() {

    }

