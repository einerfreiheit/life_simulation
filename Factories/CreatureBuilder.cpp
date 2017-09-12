#include "CreatureBuilder.h"
#include "GenomeBuilder.h"
#include "../Genetics/GenomeVisualizer.h"
#include "PhenotypeBuilder.h"
#include <iostream>
#include <string>
#include "./SimulationData.h"

std::string CreatureBuilder::path = SimulationData::getInst()->outputPath;//@ лучше 3 раза написать явно, чем вызывать такое до int main
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

	world->map[posY][posX].creatures.push_back(result);
	cv::Mat vis = GenomeVisualizer::visualize(genome);
	cv::imwrite(path + std::to_string(nextId) + ".png", vis);
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

	world->map[result->y][result->x].creatures.push_back(result);

	cv::Mat vis = GenomeVisualizer::visualize(genome);
	cv::imwrite(path + std::to_string(nextId) + ".png", vis);

	return result;

}

CreaturePtr CreatureBuilder::build(World *world, GenomePtr loadedGenome,int posX, int posY) {

	CreaturePtr result = std::shared_ptr<Creature>(new Creature(nextId++));

	result->energy = 100.0;
	PhenotypePtr phenotype = PhenotypeBuilder::build(loadedGenome);

	result->setGenome(loadedGenome);
	result->setPhenotype(phenotype);

	world->map[posY][posX].creatures.push_back(result);

	cv::Mat vis = GenomeVisualizer::visualize(loadedGenome);//@ вынести в метод
	cv::imwrite(path + std::to_string(nextId) + ".png", vis);

	return result;

}
