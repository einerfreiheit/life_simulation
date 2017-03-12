#include "Move.h"

Move::Move() {
}
void Move::act(World *world, Creature &creature) {
	int y = creature.getPosY();//@ в идеале в классе Move уже должна содержаться инфа о том, куда хочет двинуться червь
	int x = creature.getPosX();//@ а направление движения должна логика заполнять
	int borderY = world->mapHeight;
	int borderX = world->mapWidth;
	Cell &cell = world->map[y][x];

	side = rand() % 4;
	switch (side) {
	case WT_DOWN: {
		if (y > 0)
			y--;
		else
			y++;
		break;
	}
	case WT_UP: {
		if (y < borderY - 1)
			y++;
		else
			y--;
		break;
	}
	case WT_LEFT: {
		if (x > 0)
			x--;
		else
			x++;
		break;
	}
	case WT_RIGHT: {
		if (x < borderX - 1)
			x++;
		else
			x--;
		break;
	}

	}
	creature.energy = creature.energy - creature.energyToMove;
	creature.setPosX(x);
	creature.setPosY(y);
}
Move::~Move() {

}

