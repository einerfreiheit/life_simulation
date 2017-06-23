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
	GenomeBuilder::crossingOver(result);

	return result;

}
void GenomeBuilder::crossingOver(GenomePtr genome) {
	int numberOfCrossingOver = SimulationData::getInst()->numberOfMitoseCrossingOver;
	while (numberOfCrossingOver > 0) {
		Gene &randomGene = GenomeBuilder::getRandomGene(genome);
		double allel1 = randomGene.allel1;
		randomGene.allel1 = randomGene.allel2;
		randomGene.allel2 = allel1;
		numberOfCrossingOver--;
	}
}
void GenomeBuilder::buildPlasmid(const GenomePtr genome) {
	ChromosomePtr plasmidChromosome(new Chromosome);
	int randomChromosome = rand() % genome->chromosomes.size();
	plasmidChromosome->genes = genome->chromosomes[randomChromosome]->genes;
	genome->plasmid.push_back(plasmidChromosome);
}

Gene& GenomeBuilder::getRandomGene(const GenomePtr genome) {
	int chromosomeNumber = genome->chromosomes.size();
	int randomChromosome = rand() % chromosomeNumber;
	int randomGene = rand() % genome->chromosomes[randomChromosome]->genes.size();
	return genome->chromosomes[randomChromosome]->genes[randomGene];

}

void GenomeBuilder::insertPlasmidToGenome(GenomePtr genome) {

	size_t plasmidSize = genome->plasmid.front()->genes.size();
	int &position = genome->plasmid.front()->position;
	while (position < plasmidSize) {
		Gene &plasmidGene = genome->plasmid.front()->genes[position];
		GenomeBuilder::replaceGene(genome, plasmidGene);
		position++;

	}
	position = 0;

}

void GenomeBuilder::replaceGene(GenomePtr recipient, Gene &plasmidGene) {
	for (ChromosomePtr chromosome : recipient->chromosomes) {
		for (Gene & gene : chromosome->genes) {
			if (gene.type == plasmidGene.type) {
				gene.allel1 = plasmidGene.allel1;
				gene.allel2 = plasmidGene.allel2;
				return;

			}

		}

	}
	if (recipient->chromosomes.back()->genes.size() >= complexityPerChromosome) {
		ChromosomePtr newChromosome(new Chromosome);
		newChromosome->genes.resize(0);
		newChromosome->genes.push_back(plasmidGene);

		recipient->chromosomes.push_back(newChromosome);

	}

}

