#ifndef VISUALIZATION_SIMPLEDISPLAY_H_
#define VISUALIZATION_SIMPLEDISPLAY_H_
#include "VisualOutput.h"

class SimpleDisplay :public VisualOutput {
public:
	SimpleDisplay();
	virtual ~SimpleDisplay();
	void update(cv::Mat* visualization)override;
};

#endif /* VISUALIZATION_SIMPLEDISPLAY_H_ */
