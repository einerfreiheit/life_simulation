#ifndef VISUALIZATION_OPENCVDATA_H_
#define VISUALIZATION_OPENCVDATA_H_

#include "../World.h"
#include"../CommonIncludes.h"


class OpenCVData {
public:
	OpenCVData(World *world);
	virtual ~OpenCVData();
	void update(World *world);
	const cv::Mat* getVisiulization();
protected:
	cv::Mat output;
	void getHeightsRange(World *world);
	float minHeight;
	float heightsRange;
};

#endif
