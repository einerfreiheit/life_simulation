#ifndef WORLD_H
#define WORLD_H

#include "CommonIncludes.h"
#include <vector> //@ выпилить
#include "Cell.h"
#include "Creature.h"

class World {
public:
	World(int mapHeightToSet, int mapWidthToSet);//@ ToSet не несёт дополнительного смысла
	~World();
	Cell* getCell(int y,int x) ;
	std::vector<std::vector<Cell> > map;
	std::vector<CreaturePtr> creatures;

};

#endif
