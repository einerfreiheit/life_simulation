#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Factories/HeightsBuilder.h"
#include "Factories/ResourceFactory.h"
#include "Factories/CreatureBuilder.h"
#include "Genetics/XmlGenomeExporter.h"
#include "Genetics/XmlGenomeLoader.h"

SimulationRunner::SimulationRunner() {
	srand(7 * clock() + time( NULL));
	world = new World(SimulationData::getInst()->mapHeight, SimulationData::getInst()->mapWidth);
	HeightsBuilder::build(world);
	ResourceFactory::addWater(world);
	world->creatures.push_back(CreatureBuilder::build(world, 1, 1));
	//world->creatures.push_back(CreatureBuilder::build(world,XmlGenomeLoader::buildGenome("genome_id_0.xml"), 1, 1));
	//XmlGenomeExporter::buildXml(world->creatures[0]);

}

SimulationRunner::~SimulationRunner() {
}

void SimulationRunner::run() {
	WorkerFactory::build(world, workers);

	while (true) {
		for (auto worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);
		}
	}
}
