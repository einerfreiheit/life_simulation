#include "CreatureActionWorker.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"

CreatureActionWorker::CreatureActionWorker() {
	this->name = "CreatureActionWorker";
}

CreatureActionWorker::~CreatureActionWorker() {
}

void CreatureActionWorker::work(World *world) {
	for (CreaturePtr &creature : world->creatures) {
		uint8_t gate = 0;
		for (SimpleAction *simpleAction : creature->actions) {
			Action *actionPtr = static_cast<Action*>(simpleAction);

			if ((gate & actionPtr->getType()) == 0) {
				actionPtr->act(world, creature);
				gate |= actionPtr->getType();
			}
			delete simpleAction;

		}
		creature->energy -= 0.1;
		creature->actions.clear();
	}
}
