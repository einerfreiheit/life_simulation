#ifndef CREATUREBUILDER_H
#define CREATUREBUILDER_H

#include "../Creature.h"

class CreatureBuilder
{
public:
    static Creature *build(int posX, int posY);
private:
    static int nextId;
};

#endif // CREATUREBUILDER_H
