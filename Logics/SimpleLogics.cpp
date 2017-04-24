#include "SimpleLogics.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include <iostream>

void SimpleLogics::willToEat ( Creature& creature ) {
    creature.creatureActions.push_back ( new Eat );
    }


void SimpleLogics::creatureWill ( World* world, Creature& creature ) {
    willToEat ( creature );
    int x = creature.getPosX();
    int y = creature.getPosY();
    if ( world->map[y][x].food <= creature.phenotype->creatureOneBait ) {
        willToMove ( world, creature );
        }


    }
void SimpleLogics::willToMove ( World *world, Creature& creature ) {

    int y = creature.getPosY();
    int x = creature.getPosX();
    side = rand() % 4;
    switch ( side ) {
        case WT_DOWN: {
            y--;
            break;
            }
        case WT_UP: {
            y++;
            break;
            }
        case WT_LEFT: {
            x--;
            break;
            }
        case WT_RIGHT: {
            x++;
            break;
            }

        }

    creature.creatureActions.push_back ( new Move ( y,x ));

    }

