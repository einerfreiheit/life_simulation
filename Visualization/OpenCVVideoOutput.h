#ifndef VISUALIZATION_OPENCVVIDEOOUTPUT_H_
#define VISUALIZATION_OPENCVVIDEOOUTPUT_H_

#include "OpenCVOutput.h"

class OpenCVVideoOutput :public OpenCVOutput {
public:
	OpenCVVideoOutput();
	virtual ~OpenCVVideoOutput();
	void update(const cv::Mat* output) override;
protected:
	cv::VideoWriter *videoWriter;
	cv::Mat videoOutput;
};

#endif
