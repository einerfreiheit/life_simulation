#include "SimpleLogics.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include <iostream>

void SimpleLogics::willToEat ( CreaturePtr creature ) {
    creature->creatureActions.push_back ( new Eat );
    
    }


void SimpleLogics::creatureWill ( World* world,CreaturePtr creature) {
    willToEat ( creature );
    int x = creature->getPosX();
    int y = creature->getPosY();
    if ( world->map[y][x].food <= creature->phenotype->creatureOneBait ) {
        willToMove ( world, creature );
	
        }


    }
void SimpleLogics::willToMove ( World *world,CreaturePtr creature ) {
    
    int y = creature->getPosY();
    int x = creature->getPosX();
    int  side = rand() % 4;
    switch ( side ) {
        case 0: {
            y--;
            break;
            }
        case 1: {
            y++;
            break;
            }
        case 2: {
            x--;
            break;
            }
        case 3: {
            x++;
            break;
            }

        }
        
        
    Move *movePtr= new Move;
    movePtr->setXandY(x,y);
    creature->creatureActions.push_back (movePtr);

    }

