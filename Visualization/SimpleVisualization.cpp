#include "SimpleVisualization.h"
#include "../SimulationData.h"
#include <cmath>
#include <iostream>

const cv::Mat* SimpleVisualization::getVisualisation() {
	return &visualization;
}

void SimpleVisualization::update(const cv::Mat* visualisationPtr) {

}

void SimpleVisualization::update(World*world) {
	if (!rangeHasBeenComputed) {
		heightsRange(world);
	}
	for (int y = 0; y < world->map.size(); y++) {
		for (int x = 0; x < world->map[0].size(); x++) {

			float height = world->map[y][x].cellHeight;
			double water = world->map[y][x].water;

			uchar &blue = visualization.at<uchar>(y, 3 * x);
			uchar &green = visualization.at<uchar>(y, 3 * x + 1);
			uchar &red = visualization.at<uchar>(y, 3 * x + 2);
			uchar intensity = (height - minHeight) / (maxHeight - minHeight) * 255;

			blue = intensity;
			green = intensity;
			red = intensity;

			if (water > SimulationData::getInst()->soilWater) {
				red = 0;
				green = 0;
			}
		}
	}

	for (auto creature : world->creatures) {
		int y = creature->getPosY();
		int x = creature->getPosX();
		uchar &blue = visualization.at<uchar>(y, 3 * x);
		uchar &green = visualization.at<uchar>(y, 3 * x + 1);
		uchar &red = visualization.at<uchar>(y, 3 * x + 2);

		red = creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255;
		blue = 0;
		green = 0;
	}
}

SimpleVisualization::SimpleVisualization() {
	visualization = cv::Mat::zeros(SimulationData::getInst()->mapHeightToSet, SimulationData::getInst()->mapWidthToSet,
	CV_8UC3);

}

SimpleVisualization::~SimpleVisualization() {
}
void SimpleVisualization::heightsRange(World *world) {
	maxHeight = world->map[0][0].cellHeight;
	minHeight = world->map[0][0].cellHeight;
	double cellHeight=world->map[0][0].cellHeight ;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			cellHeight = world->map[i][j].cellHeight;
			maxHeight = std::max(maxHeight, cellHeight);
			minHeight = std::min(minHeight, cellHeight);
		}
	}

	if (maxHeight == minHeight) {
		throw std::runtime_error("float map, all heights are equal");
	}
	rangeHasBeenComputed = true;
}

