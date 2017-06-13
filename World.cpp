#include "World.h"
#include <stdexcept>
#include <string>
World::World(const int mapHeightToSet, const int mapWidthToSet) {
	map.resize(mapHeightToSet);
	for (int y = 0; y < mapHeightToSet; y++) {
		map[y].resize(mapWidthToSet);
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
	if (!cellPtr) {
		throw std::runtime_error("Check borders! Cell in y:" + std::to_string(y) + " x:" + std::to_string(x) + " does not exist");
	}
	return cellPtr;

}
