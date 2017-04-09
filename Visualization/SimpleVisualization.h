#ifndef VISUALIZATION_SIMPLEVISUALIZATION_H_
#define VISUALIZATION_SIMPLEVISUALIZATION_H_
#include "OpenCvVisualization.h"
class SimpleVisualization :public OpenCvVisualization {
public:
	SimpleVisualization();
	virtual ~SimpleVisualization();
	void display(World *world) override;
	void update(World *world) override;
	void init() override;
};

#endif /* VISUALIZATION_SIMPLEVISUALIZATION_H_ */
