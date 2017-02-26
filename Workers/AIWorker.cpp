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
	int pos=0;
	for (auto &creature:world->worm_map) {
		int x = creature.getPosX();
		int y = creature.getPosY();

		creature.isHungry=isHungry(world,y,x);
		logic.move(creature,world->mapHeight,world->mapWidth);
		eat(creature,world, y, x);

		if (isAlive(world,creature)==false){
			world->worm_map.erase(world->worm_map.begin() +pos);
			std::vector<Creature>(world->worm_map).swap(world->worm_map);

		}
		pos++;
	}
}

bool AIWorker::isHungry(World *world, int y, int x) { //@ лучше назвать метод isHungry (каждое слово с большой буквы, кроме первого
	if (world->map[y][x].food <= 1.0) {
		return true;
	} else
		return false;

}

bool AIWorker::isAlive(World *world, Creature &creature) { //@ лучше назвать метод isAlive и подавать туда сразу червя

	if (creature.energy <= 0) {
		return false;

	}
	else
		return true;

}


void AIWorker::eat(Creature &creature,World *world, int y, int x) {

	if (world->map[y][x].food > 1.0) {
		world->map[y][x].food  = world->map[y][x].food -5.0;
		creature.energy = creature.energy
				+ 10.0;

	} else
		world->map[y][x].food = 0;

} //@ научись пользоваться хотя бы автоформаттером кода. В эклипсе горячие клавиши Ctrl+Shift+F
