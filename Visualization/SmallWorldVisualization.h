#ifndef VISUALIZATION_SMALLWORLDVISUALIZATION_H_
#define VISUALIZATION_SMALLWORLDVISUALIZATION_H_
#include "Visualization.h"
#include "../World.h"
class SmallWorldVisualization :public Visualization {
public:
	SmallWorldVisualization();
	virtual ~SmallWorldVisualization();
	void computeImage(World *world) override;
	void showImage(World *world) override;
};

#endif
