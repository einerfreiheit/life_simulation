#include "Eat.h"

Eat::Eat() {

	type = AT_EAT;
}

void Eat::act(World *world, CreaturePtr creature) {

	Cell &cell = world->map[creature->y][creature->x];
	double toEat = std::min(cell.food, creature->phenotype->creatureOneBait);
	cell.food -= toEat;
	creature->energy += creature->phenotype->energyFromFood * toEat / creature->phenotype->creatureOneBait;

}

Eat::~Eat() {

}
