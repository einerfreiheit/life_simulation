#include "SmallWorldVisualization.h"
SmallWorldVisualization::SmallWorldVisualization() {

}

SmallWorldVisualization::~SmallWorldVisualization() {
}

void SmallWorldVisualization::showImage(World *world) {
	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 640, 480);
	cv::imshow("123", world->visualization);
	cv::waitKey(10);

}

void SmallWorldVisualization::computeImage(World *world) {
	cv::Mat &visual = world->visualization;

	for (int y = 0; y < world->mapHeight; y++) {
		for (int x = 0; x < world->mapWidth; x++) {
			double height = world->map[y][x].heightValue;
			float depth = world->maxH - world->minH;
			double food = world->map[y][x].food;
			int color;
			if (height >= 0) {
				color = 127 * height / depth + 128;
			} else {
				color = 128 + 127 * height / depth;
			}
			int colorDelta = std::min(255.0, food * 255.0 / 100.0);
			cv::Vec3b &pixel = visual.at<cv::Vec3b>(y, x);
			pixel[1] = std::max(color,colorDelta);
			pixel[2] = std::max(color,colorDelta);
			pixel[0]=255;

		}
	}

	for (auto creature : world->creatures) {
		cv::Vec3b &pixel = visual.at<cv::Vec3b>(creature->getPosY(),
				creature->getPosX());
		pixel[2] =
				creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255;
	pixel[0] = 0;
		pixel[1] = 0;
	}
}
