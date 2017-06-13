#include "CreatureBuilder.h"
#include "GenomeBuilder.h"
#include "../Genetics/GenomeVisualizer.h"
#include "PhenotypeBuilder.h"
#include <iostream>
#include <string>
#include "./SimulationData.h"

std::string CreatureBuilder::path = SimulationData::getInst()->outputPath;
int CreatureBuilder::nextId = 0;

CreaturePtr CreatureBuilder::build(World *world, int posX, int posY) {
	CreaturePtr result = std::shared_ptr<Creature>(new Creature(nextId++));
	result->x = posX;
	result->y = posY;
	result->energy = 100.0;
	//@ временно пусть будет так
	//@ можешь папку создать и посмотреть на выхлоп
	GenomePtr genome = GenomeBuilder::build(15 + rand() % 8);
	PhenotypePtr phenotype = PhenotypeBuilder::build(genome);

	result->setGenome(genome);
	result->setPhenotype(phenotype);

	for (ChromosomePtr chromosome : result->getGenome()->chromosomes) {
		for (Gene &gene : chromosome->genes) {

			for (Gene &gene : chromosome->genes) {

				//@ что?

			}
			result->phenotype->cellReceptor += std::to_string(gene.type);

		}

	}

	world->map[posY][posX].creaturesInCell.push_back(result);

	cv::Mat vis = GenomeVisualizer::visualize(genome);

	cv::imwrite(path + std::to_string(nextId) + ".png", vis);
	std::cout << result->phenotype->cellReceptor << std::endl;
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

	world->map[result->y][result->x].creaturesInCell.push_back(result);

	cv::Mat vis = GenomeVisualizer::visualize(genome);
	cv::imwrite(path + std::to_string(nextId) + ".png", vis);

	return result;

}
