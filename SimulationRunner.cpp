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
#include "../Workers/OpenGLWorldRenderer.h"

SimulationRunner::SimulationRunner() {
	srand(7 * clock() + time( NULL));
	world = new World(SimulationData::getInst()->mapHeightToSet, SimulationData::getInst()->mapWidthToSet);


	HeightsBuilder::build(world);
	ResourceFactory::addWater(world);
	workers.push_back(new OpenGLWorldRenderer(world));
	world->creatures.push_back(CreatureBuilder::build(world, 0,0));
	//world->creatures.push_back(CreatureBuilder::build(world,XmlGenomeLoader::buildGenome("genome_id_0.xml"), 1, 1));
	//XmlGenomeExporter::buildXml(world->creatures[0]);


}

SimulationRunner::~SimulationRunner() {
}

void SimulationRunner::run() {
	WorkerFactory::build(workers);

	while (true) {
		for (auto worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);
		}
	}
}
