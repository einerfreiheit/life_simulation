#ifndef WORLD_H
#define WORLD_H

#include "CommonIncludes.h"
#include "Cell.h"
#include "Creature.h"

class World {
public:
	World(int mapHeigh, int mapWidth);
	~World();
	Cell* getCell(int y,int x) ;
	std::vector<std::vector<Cell> > map;
	std::vector<CreaturePtr> creatures;

};

#endif
