#include "Conjugate.h"
#include <stdlib.h>
#include <vector>
#include "../Factories/GenomeBuilder.h"

Conjugate::Conjugate() {
	type = AT_CONJUGATE;
}

Conjugate::~Conjugate() {
}

void Conjugate::act(World* world, CreaturePtr creature) {
	int id = creature->getId();
	Cell& cell = world->map[creature->y][creature->x];

	for (auto otherCreature : cell.creaturesInCell) {
		if (creature->phenotype->conjugateEnergy < creature->energy) {
			break;
		}
		if (otherCreature->getId() != id && canConjugate(creature, otherCreature)) {
			conjugate(creature, otherCreature);
		}
	}
}

bool Conjugate::canConjugate(CreaturePtr firstCreature, CreaturePtr secondCreature) {
	return secondCreature->getGenome()->plasmide.size();
}

void Conjugate::conjugate(CreaturePtr firstCreature, CreaturePtr secondCreature) {
	GenomePtr firstGenome = firstCreature->getGenome();
	GenomePtr secondGenome = secondCreature->getGenome();

	GenomeBuilder::buildPlasmide(firstGenome);
	secondGenome->plasmide = firstGenome->plasmide;

	updateGenome(secondCreature);
}

void Conjugate::updateGenome(CreaturePtr creature) {
	GenomePtr genome = creature->getGenome();
	size_t plasmideSize = genome->plasmide.front()->genes.size();
	int &position = genome->plasmide.front()->position;
	position = 0;

	while (genome->plasmide.front()->position != plasmideSize) {
		replaceGene(genome, genome->plasmide.front()->genes[position]);
		position++;

	}

}

void Conjugate::replaceGene(GenomePtr genome, Gene& plasmideGene) {
	for (ChromosomePtr chromosome : genome->chromosomes) {
		for (Gene & gene : chromosome->genes) {
			if (gene.type == plasmideGene.type) {
				changeAllels(plasmideGene, gene);
				return;

			}

		}

	}
	changeAllels(plasmideGene, GenomeBuilder::getRandomGene(genome));
}

void Conjugate::changeAllels(Gene& geneFirst, Gene& geneSecond) //@ из названий не ясно, что и где меняется
								{
	bool reverseAllel = rand() % 2;
	if (reverseAllel) {
		geneSecond.allel1 = geneFirst.allel2;
		geneSecond.allel2 = geneFirst.allel1;

	}
	else {
		geneSecond.allel1 = geneFirst.allel1;
		geneSecond.allel2 = geneFirst.allel2;
	}
}
