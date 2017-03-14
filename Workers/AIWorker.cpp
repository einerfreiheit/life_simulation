#include "AIWorker.h"
#include <iostream>
#include "Logics/SimpleLogics.h"

AIWorker::AIWorker() {
	this->name = "AIWorker";

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {

	for (auto creature : world->creatures) {
		std::vector<Action*> actions;

		simplelogic.findFood(world,*creature,actions);

		for (Action* action :actions){
			action->act(world,*creature);
			std::cout<<"act";
		}
		actions.erase(actions.begin(),actions.end());
//		simplelogic.actions.clear();//@ не очень здорово, что simplelogic имеет внутреннее состояние, которое может меняться - убивается многопоточность
//		std::cout<<creature->energy<<std::endl;//@ было бы лучше, если бы simplelogic хотя бы по ссылке заполнял вектор действий
		//@ или чтобы вектор действий был внутри самого существа, и этот вектор потом кто-нибудь процессил
	}
}

