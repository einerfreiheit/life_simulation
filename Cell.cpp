#include "Cell.h"
#include <cstdlib>

Cell::Cell()  {
	food = rand() % 100;
	water=0.0;
	height=0.0;
	creaturesInCell.reserve(5);

}

Cell::~Cell() {

}

