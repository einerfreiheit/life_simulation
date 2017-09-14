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
	for (auto otherCreature : world->getCell(creature->y,creature->x)->creatures) {
		if (otherCreature->getId() != id && canConjugate(otherCreature)) {
			conjugate(creature, otherCreature);
			creature->stats->incrementConjugationNumber();
			return;
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
