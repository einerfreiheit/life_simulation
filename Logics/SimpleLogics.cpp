#include "SimpleLogics.h"
#include "CreatureLogic.h"
#include <iostream>

SimpleLogics::SimpleLogics() {

}
void SimpleLogics::findFood(World*world,Creature& creature,std::vector<Action*> &actions){
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];
	if (cell.food > creature.creatureOneBait) {
		actions.push_back(new Eat);
		std::cout<<"added eat";
	}
	else {
		actions.push_back(new Move);
		std::cout<<"added move";
	}


}


SimpleLogics::~SimpleLogics() {

}

