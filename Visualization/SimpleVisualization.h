#ifndef VISUALIZATION_SIMPLEVISUALIZATION_H_
#define VISUALIZATION_SIMPLEVISUALIZATION_H_

#include "OpenCvVisualization.h"

class SimpleVisualization: public OpenCvVisualization {
public:
	SimpleVisualization();
	virtual ~SimpleVisualization();
	void update(World *world) override;
	void update(const cv::Mat* visualisationPtr) override;
	const cv::Mat* getVisualisation();
private:
	double minHeight;
	double maxHeight;
	bool rangeHasBeenComputed = false;
	void heightsRange(World *world);

};

#endif
