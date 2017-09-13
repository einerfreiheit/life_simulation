#ifndef VISUALIZATION_OPENCVOUTPUT_H_
#define VISUALIZATION_OPENCVOUTPUT_H_

#include"../CommonIncludes.h"

class OpenCVOutput {
public:
	OpenCVOutput() {
	}
	;
	virtual ~OpenCVOutput() {
	}
	;
	virtual void update(const cv::Mat* output)=0;
};

#endif
