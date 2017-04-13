#include "SimpleDisplay.h"

SimpleDisplay::SimpleDisplay() {
	// TODO Auto-generated constructor stub

}

SimpleDisplay::~SimpleDisplay() {
	// TODO Auto-generated destructor stub
}
void SimpleDisplay::update(cv::Mat* visualization) {

	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 640, 480);
	cv::imshow("123", *visualization);
	cv::waitKey(10);
}
