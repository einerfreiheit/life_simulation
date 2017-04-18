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
	      Action *actionPtr= static_cast<Action*>(simpleAction);      
	      actionPtr->act(world,*creature);
	      delete simpleAction;
	      
            }
        creature->creatureActions.clear();
	

        }

    }

