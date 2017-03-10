#include "Eat.h"

Eat::Eat() {
}
void Eat::act(World *world, Creature &creature) {
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];

	cell.food -= creature.creatureOneBait;
	creature.energy += creature.energyFromFood;

}
Eat::~Eat() {
}
