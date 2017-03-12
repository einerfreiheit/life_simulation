#include "Eat.h"

Eat::Eat() {
}
void Eat::act(World *world, Creature &creature) {
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];

	cell.food -= creature.creatureOneBait;//@ в самих действиях должны быть проверки на возможность их осуществить, а в логике могут быть просто хотелки
	creature.energy += creature.energyFromFood;

}
Eat::~Eat() {
}
