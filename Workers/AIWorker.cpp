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
		simplelogic.actions.clear();//@ не очень здорово, что simplelogic имеет внутреннее состояние, которое может меняться - убивается многопоточность
		std::cout<<creature->energy<<std::endl;//@ было бы лучше, если бы simplelogic хотя бы по ссылке заполнял вектор действий
		//@ или чтобы вектор действий был внутри самого существа, и этот вектор потом кто-нибудь процессил
	}
}

