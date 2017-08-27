#include "SimpleLogics.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include "../Actions/Attack.h"
#include "../Actions/Conjugate.h"
#include <iostream>

void SimpleLogics::willToEat(CreaturePtr creature) {
	creature->creatureActions.push_back(new Eat);

}

void SimpleLogics::creatureWill( World* world, CreaturePtr creature) {
	willToAttack(creature);
	willToEat(creature);
	creature->creatureActions.push_back(new Conjugate);

	if (creature->hasBeenAttaked && creature->phenotype->healthPoints <= 50) {
		willToMove(creature);
	}
	else {
		Cell * cell = world->getCell(creature->y, creature->x);

		if (cell->food <= creature->phenotype->creatureOneBait) {
			willToMove( creature);
		}

	}
	creature->hasBeenAttaked = false;
}
void SimpleLogics::willToAttack(CreaturePtr creature) {
	if (creature->phenotype->aggresion >0.0) creature->creatureActions.push_back(new Attack);

}

void SimpleLogics::willToMove(CreaturePtr creature) {

	int y = 0;
	int x = 0;
	int side = rand() % 4;
	switch (side) {
	case 0: {
		y--;
		break;
	}
	case 1: {
		y++;
		break;
	}
	case 2: {//@ зачем?! ну зачем?!
		x--;
		break;
	}
	case 3:
	    x++;
	    break;
	}


	creature->creatureActions.push_back(new Move(y,x));

}

