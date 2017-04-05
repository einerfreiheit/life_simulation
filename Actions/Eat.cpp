#include "Eat.h"

Eat::Eat() {
}
void Eat::act(World *world, Creature &creature) {
	int y = creature.getPosY();//@ вот тут тоже, x и y используются только один раз дальше, можно напрямую писать геттеры при обращении к карте
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];
	double energyFromFood=SimulationData::getInst()->energyFromFood;//@ эти штуки используются мало раз, поэтому можно даже без дополнительных переменных их где надо брать прямо из конфига
	double creatureOneBait=SimulationData::getInst()->creatureOneBait;


	if (cell.food > energyFromFood) {
		cell.food -=creatureOneBait;
		creature.energy +=energyFromFood;
	}

}
Eat::~Eat() {
}
