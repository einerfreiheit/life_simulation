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

		for (std::shared_ptr<SimpleAction> simpleAction : creature->creatureActions) {
//			std::unique_ptr<Action> action;
			std::static_pointer_cast<Action>(simpleAction)->act(world,*creature);
//			action = static_cast<Action*>(simpleAction);
//			action->act(world, *creature);


		}



		creature->creatureActions.clear();


	}

}

