#ifndef VISUALIZATION_VISUALIZATION_H_
#define VISUALIZATION_VISUALIZATION_H_
#include"../CommonIncludes.h"
#include "../World.h"

class Visualization {
public:
	Visualization();
	virtual ~Visualization();
	virtual void visualize(World *world);
	virtual void computeImage(World *world)=0;
	virtual void showImage(World *world)=0;
};

#endif
