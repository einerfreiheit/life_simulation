#include "Cell.h"
#include <cstdlib>
#include <string>
#include <stdexcept>

Cell::Cell() {
	food = rand() % 100;
	water = 0.0;
	height = 0.0;
	creaturesInCell.reserve(5);

}

Cell::~Cell() {

}

void Cell::removeCreature(int id) {
	bool hasBeenRemoved = false;
	if (creaturesInCell.size() == 0) {
		throw std::runtime_error("cell is empty, creature id " + std::to_string(id) + "cannot be removed");
	}
	for (int j = 0; j < creaturesInCell.size(); j++) {
		if (creaturesInCell[j]->getId() == id) {
			creaturesInCell[j] = creaturesInCell[creaturesInCell.size() - 1];
			creaturesInCell.resize(creaturesInCell.size() - 1);
			hasBeenRemoved = true;
			break;
		}
		if (!hasBeenRemoved) {
			throw std::runtime_error("cannot find and remove creature from cell");
		}

	}
}
