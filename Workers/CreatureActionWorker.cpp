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

 	creature->creatureActions.erase(creature->creatureActions.begin(),creature->creatureActions.end());//@ зачем тут так сложно писать, когда можно просто clean сделать?
//@ещё у тебя тут утечка памяти. Все действия ты создаёшь оператором new, значит, тебе либо надо в конце все действия удалить с помощью delete, либо воспользоваться штукой, которая умеет вызывать delete сама, когда надо (умный указатель)
	//@ vector erase не умеет сам вызывать delete для элементов, так как вектор просто _не знает_, что находится внутри него: указатель?, объект?, число? - хз
            
        }

}

