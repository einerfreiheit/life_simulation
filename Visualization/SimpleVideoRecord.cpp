#include "SimpleVideoRecord.h"
#include "../SimulationData.h"
#include <iostream>
SimpleVideoRecord::SimpleVideoRecord() {
	output = cv::Mat::zeros(SimulationData::getInst()->mapWidthToSet,
			SimulationData::getInst()->mapHeightToSet, CV_8UC3);
	writer.open("./output.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0,
			output.size(), true);
}

SimpleVideoRecord::~SimpleVideoRecord() {
}
void SimpleVideoRecord::update(cv::Mat* visualization) {

	cv::resize(*visualization, output, output.size(), 1, 1, cv::INTER_NEAREST);
//	writer.write(output);


//	cv::namedWindow("debug",CV_WINDOW_NORMAL);
//		cv::resizeWindow("debug", 640, 480);
//		cv::imshow("debug", output);
		writer.write(output);
//		cv::waitKey(10);
	output.release();

}

