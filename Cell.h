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
	float height;

	void removeCreature(int id);
	std::vector<CreaturePtr> creaturesInCell; //@ Cell.creaturesInCell
	int xCoordinate;//@ просто x и просто y
	int yCoordinate;
};

#endif
