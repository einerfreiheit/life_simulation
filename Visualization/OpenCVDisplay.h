#ifndef VISUALIZATION_OPENCVDISPLAY_H_
#define VISUALIZATION_OPENCVDISPLAY_H_

#include "OpenCVOutput.h"

class OpenCVDisplay :public OpenCVOutput {
public:
	OpenCVDisplay();
	virtual ~OpenCVDisplay();
	void update(const cv::Mat* output) override;
};

#endif
