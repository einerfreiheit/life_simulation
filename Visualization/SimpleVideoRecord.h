#ifndef VISUALIZATION_SIMPLEVIDEORECORD_H_
#define VISUALIZATION_SIMPLEVIDEORECORD_H_
#include "OpenCvVisualization.h"

class SimpleVideoRecord: public OpenCvVisualization
{
public:
    SimpleVideoRecord();
    virtual ~SimpleVideoRecord();
    void update ( const cv::Mat* visualization ) override;
    void update (World*world) override;
private:
    cv::VideoWriter writer;
};

#endif /* VISUALIZATION_SIMPLEVIDEORECORD_H_ */
