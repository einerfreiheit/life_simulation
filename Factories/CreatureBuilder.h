#ifndef CREATUREBUILDER_H
#define CREATUREBUILDER_H

#include "../Creature.h"
#include "../World.h"

class CreatureBuilder {
public:
	static CreaturePtr build(World *world, int posX, int posY);
	static CreaturePtr build(World *world, CreaturePtr parent);
	static CreaturePtr build(World *world, GenomePtr loadedGenom, int posX, int posY);
private:
	static int nextId;
	static void writeGenomeImage(GenomePtr genome);

};

#endif
