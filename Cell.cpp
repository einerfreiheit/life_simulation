#include "Cell.h"
#include <cstdlib>

Cell::Cell() {
	food = rand() % 100;
	creaturesInCell.reserve(10);

}

Cell::~Cell() {

}

