#ifndef HEIGHTS_H_
#define HEIGHTS_H_
#include "World.h"
class Heights {
public:
	Heights(World *world);
	virtual ~Heights();
	void getDepth(float &minH, float &maxH);
	void DiamondSquare(float range);
private:

	double rangedRandom();
	void setCorners(int height, int width);
	int step;
	bool checkBorders(int y, int x);
	void diamondStep(int y, int x, float range);

	World * world;
	int height;
	int width;

};

#endif
