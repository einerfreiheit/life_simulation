#ifndef VISUALIZATION_SIMPLEVIDEORECORD_H_
#define VISUALIZATION_SIMPLEVIDEORECORD_H_
#include "VisualOutput.h"

class SimpleVideoRecord: public VisualOutput
{
public:
    SimpleVideoRecord();
    virtual ~SimpleVideoRecord();
    void update ( cv::Mat* visualization ) override;
private:
    cv::VideoWriter writer;
};

#endif /* VISUALIZATION_SIMPLEVIDEORECORD_H_ */
