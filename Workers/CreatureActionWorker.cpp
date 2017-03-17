#include "CreatureActionWorker.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include "../Actions/Action.h"
#include "../Actions/SimpleAction.h"

CreatureActionWorker::CreatureActionWorker() {
	this->name = "CreatureActionWorker";

}

CreatureActionWorker::~CreatureActionWorker() {
}

void CreatureActionWorker::work(World *world) {
	for (auto creature : world->creatures) {
		for (SimpleAction* simpleAction:creature->creatureActions){

			Action * action;
			action=static_cast <Action*>(simpleAction);
			action->act(world,*creature);



			}

		creature->creatureActions.erase(creature->creatureActions.begin(),creature->creatureActions.end());

	}

}

