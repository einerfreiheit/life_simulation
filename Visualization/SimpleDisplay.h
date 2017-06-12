#ifndef VISUALIZATION_SIMPLEDISPLAY_H_
#define VISUALIZATION_SIMPLEDISPLAY_H_

#include "OpenCvVisualization.h"

class SimpleDisplay: public OpenCvVisualization {
public:
	SimpleDisplay();
	virtual ~SimpleDisplay();
	void update(const cv::Mat* visualization) override;
	void update(World*world) override;

};

#endif
