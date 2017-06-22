#include "Creature.h"
#include <iostream>

Creature::Creature(int _id) :
		id(_id) {
	energy = 0.0;
	x = 0;
	y = 0;

}



int Creature::getId() const {
	return id;
}

bool Creature::isHungry() const {

	return this->energy <= phenotype->hungryEdge;
}

void Creature::setPhenotype(PhenotypePtr _phenotype) {
	this->phenotype = _phenotype;

}

void Creature::setGenome(GenomePtr _genome) {
	this->genome = _genome;
}

GenomePtr Creature::getGenome ( ) const {
	return genome;
}

Creature::~Creature() {
	std::cout << getId() << " creature deleted" << std::endl;
}

