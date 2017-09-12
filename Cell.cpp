#include "Cell.h"
#include <cstdlib>
#include <string>
#include <stdexcept>

Cell::Cell() {
	food = rand() % 100;
	water = 0.0;
	height = 0.0;
	creatures.reserve(5);

	heights.resize(2);
	for (int i = 0; i < heights.size(); i++) {
		heights[i].resize(2);
	}
}

Cell::~Cell() {

}

void Cell::removeCreature(int id) {
	if (creatures.size() == 0) {
		throw std::runtime_error("cell is empty, creature id " + std::to_string(id) + "cannot be removed");
	}
	for (int j = 0; j < creatures.size(); j++) {
		if (creatures[j]->getId() == id) {
			creatures[j] = creatures[creatures.size() - 1];
			creatures.resize(creatures.size() - 1);
			return;
		}

	}

	throw std::runtime_error("cannot find and remove creature id " + std::to_string(id) + " from cell");

}
