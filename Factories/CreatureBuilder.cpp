#include "CreatureBuilder.h"

int CreatureBuilder::nextId = 0;

Creature *CreatureBuilder::build(int posX, int posY){
    Creature *result = new Creature(nextId++);
    result->setPosX(posX);
    result->setPosY(posY);
    result->setEnergy(100);
    return result;
}