#ifndef VISUALIZATION_SIMPLEVISUALIZATION_H_
#define VISUALIZATION_SIMPLEVISUALIZATION_H_
#include "OpenCvVisualization.h"
class SimpleVisualization :public OpenCvVisualization {
public:
	SimpleVisualization();
	virtual ~SimpleVisualization();

	void update(World *world) override;
	cv::Mat*  getVisualisation() override;
};

#endif /* VISUALIZATION_SIMPLEVISUALIZATION_H_ */
