#ifndef DIAMONDSQUARE_H
#define DIAMONDSQUARE_H

#include "../World.h"

class DiamondSquare {
public:
	DiamondSquare(World*world);
	~DiamondSquare();

private:
	void diamondSquare(World*world, double scale);
	void init(World *world);
	void diamondStep(World* world, int y, int x, double scale);
	void squareStep(World *world, int y, int x, double scale);
	double rangedRandom();
	void setDepth(World *world);
	bool checkIndex(int index, int size);
	int step;
};

#endif
