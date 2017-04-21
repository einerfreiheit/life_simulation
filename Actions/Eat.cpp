#include "Eat.h"
Eat::Eat() {

    type=AT_EAT;
}
void Eat::act ( World *world, Creature &creature ) {

    Cell &cell = world->map[creature.getPosY()][creature.getPosX()];
    if ( cell.food > creature.getPhenotype()->creatureOneBait ) {
        cell.food -=creature.getPhenotype()->creatureOneBait;
        creature.energy +=creature.getPhenotype()->energyFromFood;
        }

    }
Eat::~Eat() {

    }
