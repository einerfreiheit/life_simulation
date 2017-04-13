#ifndef VISUALIZATION_OPENCVVISUALIZATION_H_
#define VISUALIZATION_OPENCVVISUALIZATION_H_
#include "Visualization.h"

class OpenCvVisualization: public Visualization {
public:
	OpenCvVisualization();
	virtual ~OpenCvVisualization();

	virtual void update(World* world)=0;

protected:
	cv::Mat visualization;
};

#endif /* VISUALIZATION_OPENCVVISUALIZATION_H_ */
