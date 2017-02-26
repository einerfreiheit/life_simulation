/*
 * CreatureLogic.cpp
 *
 *  Created on: 26 февр. 2017 г.
 *      Author: lenovo
 */

#include "CreatureLogic.h"
#include <cstdlib>
CreatureLogic::CreatureLogic() {
}

CreatureLogic::~CreatureLogic() {

}
void CreatureLogic::move(Creature &creature, int borderY, int borderX) {
	int y = creature.y;
	int x = creature.x;
	if (creature.isHungry == true) {
		way = rand() % 4;
		switch (way) {
		case WT_DOWN: {
			if (y > 0)
				y = y - 1;
			else
				y = y + 1;
			break;
		}
		case WT_UP: {
			if (y < borderY - 1)
				y = y + 1;
			else
				y = y - 1;
			break;
		}
		case WT_LEFT: {
			if (x > 0)
				x = x - 1;
			else
				x = x + 1;
			break;
		}
		case WT_RIGHT: {
			if (x < borderX - 1)
				x = x + 1;
			else
				x = x - 1;
			break;
		}
		}
	}

	creature.setPosX(x);
	creature.setPosY(y);
	creature.energy -= 5;
}

bool CreatureLogic::isAlive(Creature &creature) {

	if (creature.energy <= 0) {
		return false;

	} else
		return true;

}
