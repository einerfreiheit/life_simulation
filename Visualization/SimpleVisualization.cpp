#include "SimpleVisualization.h"
#include "../SimulationData.h"
#include <iostream>


cv::Mat*const  SimpleVisualization::getVisualisation(){

	return &visualization;
}

void SimpleVisualization::update(World*world) {
	float depth = world->heightsRange;

	for (int y = 0; y < world->mapHeight; y++) {
		for (int x = 0; x < world->mapWidth; x++) {
			double height = world->map[y][x].heightValue;
			double food = world->map[y][x].food;
			int color=0;
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
	visualization = cv::Mat::zeros(SimulationData::getInst()->mapWidthToSet,
				SimulationData::getInst()->mapHeightToSet, CV_8UC3);

}
SimpleVisualization::~SimpleVisualization() {

}

