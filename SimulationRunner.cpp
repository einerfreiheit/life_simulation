#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
using namespace std;//@ надо отучиваться писать такие штуки, они развращают

SimulationRunner::SimulationRunner() {

}

SimulationRunner::~SimulationRunner() {

}

void SimulationRunner::init() {
	srand(7 * clock() + time(NULL));
	SimulationData::getInst();//@ нет смысла тут вызывать заранее, в следующей строчке всё уже построится
	world = SimulationData::getInst()->world;

	factory.build(new AIWorker);//@ совсем неправильное понимание фабрики
	factory.build(new CreatureRemoveWorker);//@ ты написал таможню, а не фабрику
	factory.build(new CreatureSpawnWorker);//@ таможня смотрит грузы и какие-то грузы пропускает
	factory.build(new ResourceWorker);//@ фабрика должна самостоятельно строить вектор объектов и сразу его выдавать
	factory.build(new VideoWriterWorker);
	factory.build(new VisualWorker);
	factory.build(new WaiterWorker);//@ все вот эти создания объектов должны происходить внутри фабрики - в этом её смысл

}

void SimulationRunner::run() {
	while (true) {
		for (WorldWorker *worker : factory.workers) {//@ так оказывается твоя таможня ещё и не возвращает вектор объектов, а оставляет себе
			std::cout << worker->getName() << std::endl;//@ так что это даже не таможня, а общак
			worker->work(world);

		}

	}
}
