#include "SimpleLogics.h"
#include "CreatureLogic.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include <iostream>

void SimpleLogics::findFood(World*world, Creature& creature) {


	    logicEat(creature);
	    int x=creature.getPosX();
	    int y=creature.getPosY();
	    if (world->map[y][x].food<creature.creatureOneBait)
		{
			logicMove(world, creature);
		}


}

void SimpleLogics::logicEat(Creature&creature) {
	creature.creatureActions.push_back(new Eat);
	std::cout << "added eat";

}

void SimpleLogics::logicMove(World *world, Creature&creature) {

	int y = creature.getPosY();
	int x = creature.getPosX();

	side = rand() % 4;
	switch (side) {
	case WT_DOWN: {
		y--;
		break;
	}
	case WT_UP: {
		y++;
		break;
	}
	case WT_LEFT: {
		x--;
		break;
	}
	case WT_RIGHT: {
		x++;
		break;
	}

	}



	Move *move = new Move;
	move->dx=x;
	move->dy=y;

	creature.creatureActions.push_back(move);
	std::cout << "added move";

}

SimpleLogics::SimpleLogics() {

}
;
SimpleLogics::~SimpleLogics() {
}
;
