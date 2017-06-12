#ifndef CELL_H_
#define CELL_H_

#include "Creature.h"
#include <vector>

class Cell {
public:
	Cell();
	virtual ~Cell();

	double food;
	double water = 0;
	double cellHeight = 0; //@ оставить просто поле height

	std::vector<CreaturePtr> creaturesInCell;
};

#endif
