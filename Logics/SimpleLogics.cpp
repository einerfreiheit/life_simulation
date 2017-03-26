#include "SimpleLogics.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include <iostream>



void SimpleLogics::logicEat(Creature&creature) {
	creature.creatureActions.push_back(new Eat);
	std::cout << "added eat";

}
/*void SimpleLogics::logicActions(World *world, Creature&creature) {

}

*/
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
