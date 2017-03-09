#include "World.h"
#include "CreatureLogic.h"
#include <cstdlib>
CreatureLogic::CreatureLogic() {
}

CreatureLogic::~CreatureLogic() {

}

void CreatureLogic::eat( World *world,Creature &creature) {
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];
	if (cell.food > creatureOneBait) {
		cell.food -= creatureOneBait;
		creature.energy += energyFromFood;

	} else {
		cell.food = 0.0;
	}
}
void CreatureLogic::move(World *world, Creature &creature) {
	int y = creature.getPosY();
	int x = creature.getPosX();
	int borderY = world->mapHeight;
	int borderX = world->mapWidth;
	Cell &cell = world->map[y][x];
	if (cell.food < creatureOneBait) {
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
	creature.energy -= 5;
	creature.setPosX(x);
	creature.setPosY(y);
}




