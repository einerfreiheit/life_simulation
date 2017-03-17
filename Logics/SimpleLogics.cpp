#include "SimpleLogics.h"
#include "CreatureLogic.h"
#include <iostream>

void SimpleLogics::findFood(World*world,Creature& creature){
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];
	if (cell.food > creature.creatureOneBait) {
		creature.creatureActions.push_back(new Eat);
		std::cout<<"added eat";
	}
	else {
		creature.creatureActions.push_back(new Move);
		std::cout<<"added move";
	}


}


SimpleLogics::SimpleLogics(){};
SimpleLogics::~SimpleLogics(){};
