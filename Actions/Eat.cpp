#include "Eat.h"
Eat::Eat() {

    type=AT_EAT;
}
void Eat::act ( World *world, CreaturePtr creature) {

    Cell &cell = world->map[creature->getPosY()][creature->getPosX()];
    if ( cell.food > creature->phenotype->creatureOneBait ) {
        cell.food -=creature->phenotype->creatureOneBait;
        creature->energy +=creature->phenotype->energyFromFood;
        }

    }
Eat::~Eat() {

    }
