#ifndef VISUALIZATION_SIMPLEVISUALIZATION_H_
#define VISUALIZATION_SIMPLEVISUALIZATION_H_
#include "OpenCvVisualization.h"
class SimpleVisualization: public OpenCvVisualization
{
public:
    void update ( World *world ) override;
    SimpleVisualization();
    virtual ~SimpleVisualization();
    cv::Mat* const getVisualisation();

};

#endif /* VISUALIZATION_SIMPLEVISUALIZATION_H_ */
