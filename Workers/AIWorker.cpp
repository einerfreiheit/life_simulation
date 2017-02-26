#include "AIWorker.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

AIWorker::AIWorker() {
	this->name = "AIWorker";

}

AIWorker::~AIWorker() {

}

void AIWorker::work(World *world) {
	int pos = 0;
	for (auto &creature : world->worm_map) {
		int x = creature.getPosX();
		int y = creature.getPosY();
		eat(creature, world, y, x);
		logic.move(creature, world->mapHeight, world->mapWidth);

		if (logic.isAlive(creature) == false) {
			world->worm_map.erase(world->worm_map.begin() + pos);
			std::vector<Creature>(world->worm_map).swap(world->worm_map);

		}
		pos++;
	}
}

void AIWorker::eat(Creature &creature, World *world, int y, int x) {
	if (world->map[y][x].food > creatureOneBait) {
		world->map[y][x].food -= creatureOneBait;
		creature.energy += energyFromFood;

	} else {
		world->map[y][x].food = 0.0;
	}

}
