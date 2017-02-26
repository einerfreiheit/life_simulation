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
void CreatureLogic::move(Creature &creature,int borderY, int borderX) {
	int y = creature.y;
	int x = creature.x;
	if (creature.isHungry == true) {
		way = rand() % 4;
		switch (way) {
		case down: {
			if (y > 0)
				y = y - 1;
			else
				y = y + 1;
			break;
		}
		case up: {
			if (y < borderY - 1)
				y = y + 1;
			else
				y = y - 1;
			break;
		}
		case left: {
			if (x > 0)
				x = x - 1;
			else
				x = x + 1;
			break;
		}
		case right: {
			if (x < borderX- 1)
				x = x + 1;
			else
				x = x - 1;
			break;
		}
		}
	}

	creature.x =(x);
	creature.y =(y);
	creature.energy = creature.energy  - 5;
}


