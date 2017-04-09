#include "SimpleVisualization.h"
#include "../SimulationData.h"
#include <iostream>
#include "../CommonIncludes.h"
void SimpleVisualization::display(World *world) {
	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 640, 480);
	std::cout << visualization.size();
	cv::imshow("123", visualization);
	cv::waitKey(10);

}
void SimpleVisualization::init() {
//	visualization(SimulationData::getInst()->mapWidthToSet,
//			SimulationData::getInst()->mapHeightToSet);
	visualization = cv::Mat::zeros(SimulationData::getInst()->mapWidthToSet,
			SimulationData::getInst()->mapHeightToSet, CV_8UC3);
	std::cout << "vis init is done ";




}
void SimpleVisualization::update(World *world) {
	float depth = world->maxH - world->minH;

	for (int y = 0; y < world->mapHeight; y++) {
		for (int x = 0; x < world->mapWidth; x++) {
			double height = world->map[y][x].heightValue;
			double food = world->map[y][x].food;
			int color;
			if (height >= 0) {
				color = 127 * height / depth + 128;
			} else {
				color = 128 + 127 * height / depth;
			}
			int colorDelta = std::min(255.0, food * 255.0 / 100.0);
			cv::Vec3b &pixel = visualization.at<cv::Vec3b>(y, x);
			pixel[0] = pixel[1] = pixel[2] = color;

		}
	}

	for (auto creature : world->creatures) {
		cv::Vec3b &pixel = visualization.at<cv::Vec3b>(creature->getPosY(),
				creature->getPosX());
		pixel[2] =
				creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255;
		pixel[0] = 0;
		pixel[1] = 0;
	}
}
SimpleVisualization::SimpleVisualization() {
	init();

}
SimpleVisualization::~SimpleVisualization() {
}

