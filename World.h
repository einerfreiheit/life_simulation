#ifndef WORLD_H
#define WORLD_H
#include "Factories/CreatureBuilder.h"
#include "CommonIncludes.h"
#include <vector>
#include "Cell.h"
#include "Creature.h"
class World {
public:
	World(const int mapHeightToSet, const int mapWidthToSet);
	~World();
	cv::Mat visualization;
	int mapHeight;
	int mapWidth;
	std::vector<std::vector<Cell> > map;
	std::vector<Creature *> creatures;
private:
	void init();


};

#endif
