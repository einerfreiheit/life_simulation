#include "AIWorker.h"
#include <iostream>
#include "Logics/SimpleLogics.h"

AIWorker::AIWorker() {
	this->name = "AIWorker";
	this->isAvailable = SimulationData::getInst()->AIWorkerIsAvailable;

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {

	for (auto creature : world->creatures) {

		simplelogic.findFood(world,*creature);
		for (Action* action :simplelogic.getActions()){
			action->act(world,*creature);
		}
		simplelogic.actions.clear();
		std::cout<<creature->energy<<std::endl;
	}
}

