/*
 * VisualVideoWorker.cpp
 *
 *  Created on: 12.04.2017
 *      Author: daniil
 */

#include "VisualVideoWorker.h"
#include "../../SimulationData.h"

VisualVideoWorker::VisualVideoWorker() {
	this->output = cv::Mat::zeros(SimulationData::getInst()->mapWidthToSet,
			SimulationData::getInst()->mapHeightToSet, CV_8UC3);

	writer.open("./output.avi", CV_FOURCC('M', 'J', 'P', 'G'), 1.0,
			output.size(), true);

}

VisualVideoWorker::~VisualVideoWorker() {
}

void VisualVideoWorker::work(cv::Mat* visualization) {

	cv::resize(*visualization, output, output.size(), 1, 1, cv::INTER_NEAREST);
	std::cout << output.size() << " " << visualization->size();
	//	cv::namedWindow("debug", CV_WINDOW_NORMAL);
	//		cv::resizeWindow("debug", 640, 480);
	//		cv::imshow("debug", output);
	writer.write(output);
	//	cv::waitKey(1);
	output.release();

}

