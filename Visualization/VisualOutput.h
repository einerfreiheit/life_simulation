#ifndef VISUALIZATION_VISUALOUTPUT_H_
#define VISUALIZATION_VISUALOUTPUT_H_
#include "../CommonIncludes.h"

class VisualOutput {
public:
	VisualOutput() {
	}

	virtual ~VisualOutput() {
	}

	virtual void update(cv::Mat* visualization)=0;
};

#endif /* VISUALIZATION_VISUALOUTPUT_H_ */
