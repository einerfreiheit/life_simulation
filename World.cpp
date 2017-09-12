#include "World.h"

World::World(const int mapHeightToSet, const int mapWidthToSet) {
	map.resize(mapHeightToSet);
	for (int y = 0; y < mapHeightToSet; y++) {
		map[y].resize(mapWidthToSet);
	}
	for (size_t y = 0; y < map.size(); y++) {
		for (size_t x = 0; x < map[0].size(); x++) {
			map[y][x].x = x;
			map[y][x].y = y;
		}
	}
	creatures.reserve(100);
}

World::~World() {
}

Cell* World::getCell(int y, int x) {
	if (y < 0 || x < 0 || x > map[0].size() || y > map.size()) {
		return NULL;
	}

	return &map[y][x];

}
