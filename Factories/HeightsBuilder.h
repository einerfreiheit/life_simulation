#ifndef HEIGHTSBUILDER_H_
#define HEIGHTSBUILDER_H_
#include "World.h"
class HeightsBuilder {
public:
	HeightsBuilder(World *world);
	virtual ~HeightsBuilder();
	void getDepth(float &minH, float &maxH);
	void DiamondSquare(float range);
	float cornerHeight = 1;
	float smooth = 1;
	int firstStepDecrease = 1;
	void setCorners();

private:

	float rangedRandom();
	int step;
	void diamondStep(int y, int x, float range);

	World * world;
	int height;
	int width;

};

#endif
