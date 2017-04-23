#include "CreatureActionWorker.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
CreatureActionWorker::CreatureActionWorker() {
    this->name = "CreatureActionWorker";

    }

CreatureActionWorker::~CreatureActionWorker() {
    }

void CreatureActionWorker::work ( World *world ) {
    for ( auto creature : world->creatures ) {
        uint8_t gate=0;
	
        for ( SimpleAction *simpleAction  : creature->creatureActions ) {
            Action *actionPtr= static_cast<Action*> ( simpleAction );
	    
            if ( gate!= ( gate | actionPtr->getType() ) ) {
                actionPtr->act ( world,*creature );
                gate |=actionPtr->getType();

                }

            delete simpleAction;

            }
        creature->creatureActions.clear();


        }

    }

