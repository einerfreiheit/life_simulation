#ifndef CELL_H_
#define CELL_H_

#include "Creature.h"
#include <vector>

class Cell {
public:
	Cell();
	virtual ~Cell();

	double food;
	double water;
	double height;

	std::vector<CreaturePtr> creaturesInCell;
};

#endif
