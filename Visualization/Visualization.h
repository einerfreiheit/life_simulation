#ifndef VISUALIZATION_VISUALIZATION_H_
#define VISUALIZATION_VISUALIZATION_H_
#include"../CommonIncludes.h"
#include "../World.h"

class Visualization {
public:
	Visualization();
	virtual ~Visualization();
	virtual void init();
	virtual void display(World *world)=0;
	virtual void update(World *world)=0;
     void visualize(World *world);
};

#endif
