#ifndef CREATUREBUILDER_H
#define CREATUREBUILDER_H

#include "../Creature.h"
#include "../World.h"
#include <string>

class CreatureBuilder
{
public:
    static CreaturePtr build ( World *world, int posX, int posY );
    static CreaturePtr build ( World *world, CreaturePtr parent );
private:
    static int nextId;
    static std::string path;
    
};

#endif
