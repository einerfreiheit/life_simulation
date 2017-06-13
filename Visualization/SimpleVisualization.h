#ifndef VISUALIZATION_SIMPLEVISUALIZATION_H_
#define VISUALIZATION_SIMPLEVISUALIZATION_H_

#include "OpenCvVisualization.h"

class SimpleVisualization: public OpenCvVisualization {
public:
	void update(World *world) override;
	void update(const cv::Mat* visualisationPtr) override;
	SimpleVisualization();
	virtual ~SimpleVisualization();
	const cv::Mat* getVisualisation();
private:
	double minHeight;
	double maxHeight;
	void heightsRange(World *world);
	bool rangeHasBeenComputed = false;
};

#endif
