#include "CreatureBuilder.h"
#include "GenomeBuilder.h"
#include "../Genetics/GenomeVisualizer.h"
#include "PhenotypeBuilder.h"
#include <iostream>
#include <string>
#include "./SimulationData.h"

int CreatureBuilder::nextId = 0;

CreaturePtr CreatureBuilder::build(World *world, int posX, int posY) {
	CreaturePtr result = std::shared_ptr<Creature>(new Creature(nextId++));
	result->x = posX;
	result->y = posY;
	result->energy = 100.0;
	GenomePtr genome = GenomeBuilder::build(15 + rand() % 8);
	PhenotypePtr phenotype = PhenotypeBuilder::build(genome);
	result->setGenome(genome);
	result->setPhenotype(phenotype);
	world->getCell(posY,posX)->creatures.push_back(result);

	writeGenomeImage(genome);
	return result;
}

CreaturePtr CreatureBuilder::build(World *world, CreaturePtr parent) {

	CreaturePtr result = std::shared_ptr<Creature>(new Creature(nextId++));
	result->x = parent->x;
	result->y = parent->y;
	result->energy = 100.0;
	GenomePtr genome = GenomeBuilder::build(parent);
	PhenotypePtr phenotype = PhenotypeBuilder::build(genome);

	result->setGenome(genome);
	result->setPhenotype(phenotype);

	world->getCell(parent->y,parent->x)->creatures.push_back(result);

	writeGenomeImage(genome);

	return result;

}

void CreatureBuilder::writeGenomeImage(GenomePtr genome) {
	cv::Mat vis = GenomeVisualizer::visualize(genome);
	cv::imwrite(SimulationData::getInst()->outputPath + std::to_string(nextId) + ".png", vis);

}
CreaturePtr CreatureBuilder::build(World *world, GenomePtr loadedGenome, int posX, int posY) {

	CreaturePtr result = std::shared_ptr<Creature>(new Creature(nextId++));

	result->energy = 100.0;
	PhenotypePtr phenotype = PhenotypeBuilder::build(loadedGenome);

	result->setGenome(loadedGenome);
	result->setPhenotype(phenotype);

	world->getCell(posY,posX)->creatures.push_back(result);
	writeGenomeImage(loadedGenome);

	return result;

}
