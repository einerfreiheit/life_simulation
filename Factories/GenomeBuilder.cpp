#include "GenomeBuilder.h"
#include "../SimulationData.h"

GenomePtr GenomeBuilder::build(int complexity) {
	GenomePtr result(new Genome);
	size_t chromosomesNum = complexity / complexityPerChromosome + ((complexity % complexityPerChromosome) > 0);
	result->chromosomes.resize(chromosomesNum);

	for (size_t i = 0; i < result->chromosomes.size(); i++) {
		int usedComplexity = std::min(complexity, complexityPerChromosome);
		complexity -= usedComplexity;
		ChromosomePtr &chromosome = result->chromosomes[i];
		chromosome.reset(new Chromosome);
		chromosome->genes.resize(usedComplexity);
	}

	return result;
}

GenomePtr GenomeBuilder::build(CreaturePtr creature) {
	GenomePtr parentGenome = creature->getGenome();
	GenomePtr result(new Genome);
	size_t chromosomesNum = parentGenome->chromosomes.size();
	size_t genesNum = 0;
	result->chromosomes.resize(chromosomesNum);

	for (size_t i = 0; i < chromosomesNum; i++) {
		ChromosomePtr &chromosome = result->chromosomes[i];
		chromosome.reset(new Chromosome);
		chromosome->genes = parentGenome->chromosomes[i]->genes;
	}

	int numberOfCrossingOver = SimulationData::getInst()->numberOfMitoseCrossingOver;
	while (numberOfCrossingOver) {
		Gene &randomGene = GenomeBuilder::getRandomGene(result);

		double allel1Temp = randomGene.allel1;
		randomGene.allel1 = randomGene.allel2;
		randomGene.allel2 = allel1Temp;
		numberOfCrossingOver--;
	}

	return result;

}

void GenomeBuilder::buildPlasmide(GenomePtr genome, int plasmideSize) {
	ChromosomePtr plasmide(new Chromosome);
	for (int currentPlasmideSize = 0; currentPlasmideSize < plasmideSize; currentPlasmideSize++) {

		plasmide->genes.push_back(Gene(getRandomGene(genome)));

	}
	genome->plasmide.push_back(plasmide);
}

Gene& GenomeBuilder::getRandomGene(GenomePtr genome) {
	int chromosomeNumber = genome->chromosomes.size();
	int randomChromosome = rand() % chromosomeNumber;
	int randomGene = rand() % genome->chromosomes[randomChromosome]->genes.size();
	return genome->chromosomes[randomChromosome]->genes[randomGene];

}

