#ifndef CELL_H_
#define CELL_H_

#include "Creature.h"

class Cell {
public:
	Cell();
	virtual ~Cell();

	float food;
	float water;
	float height; // временно
	int x;
	int y;
	std::vector<std::vector<float>> heights;
	std::vector<CreaturePtr> creatures;

	void removeCreature(int id);
};

#endif
