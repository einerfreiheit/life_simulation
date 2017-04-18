#include "Eat.h"
Eat::Eat() {
    }
void Eat::act ( World *world, Creature &creature ) {

    Cell &cell = world->map[creature.getPosY()][creature.getPosX()];
    if ( cell.food > SimulationData::getInst()->energyFromFood ) {
        cell.food -=SimulationData::getInst()->creatureOneBait;
        creature.energy +=SimulationData::getInst()->energyFromFood;
        }

    }
Eat::~Eat() {

    }
