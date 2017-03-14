#include "CreatureRemoveWorker.h"

CreatureRemoveWorker::CreatureRemoveWorker() {
	this->name = "CreatureRemoveWorker";

}

void CreatureRemoveWorker::work(World *world) {

	if (!world->creatures.size()) {//@ можно это условие убрать, оно избыточно, код дальше будет работать корректно и с пустым вектором червей
		return;
	}

	int lastId = (int) world->creatures.size() - 1;
	int i = 0;
	while (i <= lastId) {
		Creature *current = world->creatures[i];
		if (current->getEnergy() <= 0) {
			delete current;
			world->creatures[i] = world->creatures[lastId];
			lastId--;
		} else {
			i++;
		}
	}
	world->creatures.resize(lastId + 1);//@ надо почитать или протестировать ресайз. Что будет, если ресайз идёт к тому же самому размеру? Медленно ли это?

}
CreatureRemoveWorker::~CreatureRemoveWorker() {
}

