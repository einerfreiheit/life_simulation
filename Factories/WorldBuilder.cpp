#include "WorldBuilder.h"
#include "SimulationData.h"
#include "Factories/HeightsBuilder.h"
#include "Factories/ResourceFactory.h"
#include "Factories/CreatureBuilder.h"
#include "Genetics/XmlGenomeExporter.h"
#include "Genetics/XmlGenomeLoader.h"

World* WorldBuilder::buidWorld() {

	World *result = new World(SimulationData::getInst()->mapHeight, SimulationData::getInst()->mapWidth);
	HeightsBuilder::build(result);
	ResourceFactory::addWater(result);
	result->creatures.push_back(CreatureBuilder::build(result, 1, 1));
	//result->creatures.push_back(CreatureBuilder::build(result,XmlGenomeLoader::buildGenome("genome_id_0.xml"), 1, 1));
	//XmlGenomeExporter::buildXml(world->creatures[0]);

	return result;
}
