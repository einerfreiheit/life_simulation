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
		logic.eat(creature,world,y,x);
		logic.move(world,creature, world->mapHeight, world->mapWidth);

		if (logic.isAlive(creature) == false) {
			world->worm_map.erase(world->worm_map.begin() + pos);
			std::vector<Creature>(world->worm_map).swap(world->worm_map);

		}
		pos++;
	}
}


