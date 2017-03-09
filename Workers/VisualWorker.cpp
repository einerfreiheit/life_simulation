#include "VisualWorker.h"
#include "CommonIncludes.h"
#include <iostream>

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";
	this->isAvailable=SimulationData::getInst()->VisualWorkerIsAvailable;


}
void VisualWorker::work(World *world) {
	computingImage(world);
	showImage(world);

}

void VisualWorker::showImage(World *world) {
	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 300, 300);
	cv::imshow("123", world->visualization);
	cv::waitKey(10);

}

void VisualWorker::computingImage(World *world) {
	cv::Mat &visual = world->visualization;

	for (int y =0; y<world->mapHeight; y++) {
		for (int x = 0; x<world->mapWidth; x++) {
			double food = world->map[y][x].food;
			int colorDelta = std::min(255.0, food * 255.0 / 100.0);
			cv::Vec3b &pixel = visual.at<cv::Vec3b> (y, x);
			pixel[1] = 255 - colorDelta;
			pixel[2] = 255 - colorDelta;
			pixel[0] = 255;
		}
	}
	for (auto creature : world->creatures) {
		cv::Vec3b &pixel = visual.at<cv::Vec3b>(creature->getPosY(), creature->getPosX());
		pixel[2] = creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255;
		pixel[0] = 0;
		pixel[1] = 0;
	}
}

VisualWorker::~VisualWorker() {
}

