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

        for ( SimpleAction *simpleAction  : creature->creatureActions ) {
            uint8_t gate=255;
            Action *actionPtr= static_cast<Action*> ( simpleAction );

            if ( gate!= ( gate & ( ~actionPtr->mask ) ) ) {
                actionPtr->act ( world,*creature );
                gate=gate & ~ actionPtr->mask;

                }

            delete simpleAction;

            }
        creature->creatureActions.clear();


        }

    }

