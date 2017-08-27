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
	Cell& cell = world->map[creature->y][creature->x];//@ getter

	for (auto otherCreature : cell.creaturesInCell) {
		if (otherCreature->getId() != id && canConjugate(otherCreature)) {//@ оргия, если слишком много червей в клетке
			conjugate(creature, otherCreature);
			creature->stats->updateConjugationNumber();
		}
	}
}

bool Conjugate::canConjugate( CreaturePtr recipient) {
	return recipient->getGenome()->plasmid.empty();
}

void Conjugate::conjugate(CreaturePtr donor, CreaturePtr recipient) {
	GenomePtr donorGenome = donor->getGenome();
	GenomePtr recipientGenome = recipient->getGenome();

	if (!donorGenome->plasmid.size()) {
		GenomeBuilder::buildPlasmid (donorGenome);
	}
	recipientGenome->plasmid = donorGenome->plasmid;
	GenomeBuilder::insertPlasmidToGenome(recipientGenome);

}
