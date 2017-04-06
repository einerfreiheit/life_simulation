#ifndef HEIGHTSBUILDER_H_
#define HEIGHTSBUILDER_H_
#include "World.h"//@ отделять переводами строк разные сущности
class HeightsBuilder {
public:
	HeightsBuilder(World *world);
	virtual ~HeightsBuilder();
	void getDepth(float &minH, float &maxH);
	void DiamondSquare(float range);//@ метод с большой буквы
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
