#include "Eat.h"

Eat::Eat() {
}
void Eat::act(World *world, Creature &creature) {
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];
	double energyFromFood=SimulationData::getInst()->energyFromFood;
	double creatureOneBait=SimulationData::getInst()->creatureOneBait;


	if (cell.food > energyFromFood) {
		cell.food -=creatureOneBait;
		creature.energy +=energyFromFood;
	}

}
Eat::~Eat() {
}
