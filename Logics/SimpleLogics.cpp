#include "SimpleLogics.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include <iostream>



void SimpleLogics::logicEat ( Creature&creature ) {
    creature.creatureActions.push_back ( std::shared_ptr <Eat> ( new Eat ) );

    }

void SimpleLogics::logicMove ( World *world, Creature&creature ) {

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





    creature.creatureActions.push_back ( std::shared_ptr <Move> ( new Move ( y,x ) ) );

    }

