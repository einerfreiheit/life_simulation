#include "PhenotypeBuilder.h"
#include "../SimulationData.h"

PhenotypePtr PhenotypeBuilder::build(const GenomePtr genome) {
	PhenotypePtr result(new Phenotype);
	result->creatureOneBait = SimulationData::getInst()->creatureOneBait;
	result->energyFromFood = SimulationData::getInst()->energyFromFood;
	result->energyToMove = SimulationData::getInst()->energyToMove;
	result->fissionLoss = SimulationData::getInst()->fissionLoss;
	result->fissionThreshold = SimulationData::getInst()->fissionThreshold;
	result->hungryThershold = 100;
	result->energyToClimb = result->energyToMove * 2;

	for (const ChromosomePtr &chromosome : genome->chromosomes) {
		for (const Gene &gene : chromosome->genes) {
			PhenotypeBuilder::processGene(gene, result);
		}
	}
	result->geneTranslationNumber = std::min((int) result->geneTranslationSpeed, result->maxGeneTranslationNumber);
	result->geneTranslationNumber = std::max(result->geneTranslationNumber, 1);
	return result;
}

void PhenotypeBuilder::processGene(const Gene& gene, PhenotypePtr phenotype) {
	switch (gene.type) {
	case GT_AGRESSION:
		phenotype->aggresion += gene.allel1;
		break;
	case GT_TRANSLATION:
		phenotype->geneTranslationSpeed += gene.allel1;
		break;
	default:
		break;
	}
}

