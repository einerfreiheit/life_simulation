/*
 * VisualDisplayWorker.cpp
 *
 *  Created on: 12.04.2017
 *      Author: daniil
 */

#include "VisualDisplayWorker.h"

VisualDisplayWorker::VisualDisplayWorker() {
	// TODO Auto-generated constructor stub

}

VisualDisplayWorker::~VisualDisplayWorker() {
	// TODO Auto-generated destructor stub
}
void VisualDisplayWorker::work(cv::Mat* visualization) {

	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 640, 480);
	cv::imshow("123", *visualization);
	cv::waitKey(10);

}

