#include "World.h"

World::World(const int mapHeightToSet, const int mapWidthToSet) {
	map.resize(mapHeightToSet);
	for (int y = 0; y < mapHeightToSet; y++) {
		map[y].resize(mapWidthToSet);
	}
	for (size_t y=0;y<map.size();y++){
		for (size_t x=0; x<map[0].size();x++){
			map[y][x].xCoordinate=x;
			map[y][x].yCoordinate=y;
		}
	}
	creatures.reserve(100);
}

World::~World() {
}

Cell* World::getCell(int y, int x) {
	Cell *cellPtr = NULL;
	if (y < map.size() && x < map[0].size()) {
		cellPtr = &map[y][x];
	}

	return cellPtr;

}
