#include "OpenCVDisplay.h"

OpenCVDisplay::OpenCVDisplay() {
	cv::namedWindow("OpenCVOutput", CV_WINDOW_NORMAL);
	cv::resizeWindow("OpenCVOutput", 640, 480);

}

OpenCVDisplay::~OpenCVDisplay() {

}

void OpenCVDisplay::update(const cv::Mat *output) {
	cv::imshow("OpenCVOutput", *output);
	cv::waitKey(10);
}
