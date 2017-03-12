#include "ResourceWorker.h"
#include <cmath>
#include <cstdlib>
ResourceWorker::ResourceWorker() {
	this->name = "ResourceWorker";
	this->isAvailable=SimulationData::getInst()->ResourceWorkerIsAvailable;
	this->gainPerCell=SimulationData::getInst()->gainResourcePerCell;

}
void ResourceWorker::setRandomXY(World *world) {//@ лучше сделать этот метод статичным и инлайновым, а rand_x и rand_y передавать по ссылке
	rand_y = rand() % world->mapHeight;//@ чем плох твой подход - у этого воркера есть состояние, которое он может менять в процессе работы
	rand_x = rand() % world->mapWidth;//@ поэтому, к примеру, нельзя одного и того же воркера в нескольких потоках заставлять работать
//@ то есть ты на корню заведомо убиваешь многопоточность
//@ и, кроме того, вынесение этих переменных в поля - архитектурное уродство, потому что переменные эти используются только в одном месте
//@ и надо переименовать в getRandomXY(World *world, int &pos_x, int &pos_y);
//@ или вообще сделать метод getRandom(int &value, int border);
}

void ResourceWorker::work(World *world) {
	int cellNumber = (int )(sqrt(world->mapHeight*world->mapWidth));
	double cellGain = (world->mapHeight*world->mapWidth)*gainPerCell/cellNumber;
	for (int i = 0; i <= cellNumber; i++) {
		setRandomXY(world);
		if (world->map[rand_y][rand_x].food < (100.0 - cellGain)) {
			world->map[rand_y][rand_x].food += cellGain;
		}

	}
}
ResourceWorker::~ResourceWorker() {
}

