#include "PhenotypeBuilder.h"
#include "../SimulationData.h"

PhenotypePtr PhenotypeBuilder::build(GenomePtr genome) {
	PhenotypePtr result(new Phenotype);
	result->corpseSize = 50; //@ уже мертвый
	result->creatureOneBait = SimulationData::getInst()->creatureOneBait;
	result->energyFromFood = SimulationData::getInst()->energyFromFood;
	result->energyToMove = SimulationData::getInst()->energyToMove;
	result->fissionLoss = SimulationData::getInst()->fissionLoss;
	result->fissionThreshold = SimulationData::getInst()->fissionThreshold;
	result->hungryEdge = 100;
	result->energyToClimb = result->energyToMove * 2;

	for (const ChromosomePtr &chromosome : genome->chromosomes) {
		for (const Gene &gene : chromosome->genes) {
//@ сделать processGene(const Gene &, PhenotypePtr)
			switch (gene.type) {
			case GT_AGRESSION: {
				if (gene.allel1 > 0.0 && result->isAggresive == false) {
					result->isAggresive = true; //сделать не буль, а сумму всех агрессий, в том числе отрицательные тормозящие агрессии
					break;
				}
			}
			case GT_TRANSLATION: {
				if (gene.allel1 > 0.0) {
					result->geneTranslationSpeed += gene.allel1;
					break;
				}
			}
			default:
				break;
			}
		}
	}
	result->geneTranslationNumber = std::min(result->geneTranslationNumber, result->maxGeneTranslationNumber);

	return result;
}

