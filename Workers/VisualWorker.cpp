#include "VisualWorker.h"
#include "CommonIncludes.h"
#include <iostream>

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";

}
void VisualWorker::work(World *world) {
	computingImage(world);
	showImage(world);

}

void VisualWorker::showImage(World *world) {
	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 300, 300);
	cv::imshow("123", world->matrix);
	cv::waitKey(10);

}

void VisualWorker::computingImage(World *world) {
	cv::Mat visual = world->matrix;

	for (int y = world->getHeight() - 1; y >= 0; y--) {
		for (int x = world->getWidth() - 1; x >= 0; x--) {
			double food = world->map[y][x].food;
			int colorDelta = std::min(255.0, food * 255.0 / 100.0);
			cv::Vec3b &pixel = visual.at<cv::Vec3b>(y, x);
			pixel[1] = 255 - colorDelta;
			pixel[2] = 255 - colorDelta;
			pixel[0] = 255;
		}
	}
	for (auto &creature : world->worm_map) { //@ это называется range-based for loop
		//@ ключевое слово auto тоже хорошо, но не стоит им злоупотреблять
		//@ и плохо то, что ты классы все назвал с маленькой буквы изначально. Надо будет исправить.Так никто не делает.
		//@ если бы был класс Worm с большой буквы, я мог бы объявлять переменные так:
		//@ Worm worm;
		//@ а из-за мелкобуквенности не могу, в том числе в цикле переменная у меня поэтому currentWorm, а не просто worm
		cv::Vec3b &pixel = visual.at<cv::Vec3b>(creature.y, creature.x);
		pixel[2] = creature.isHungry() ? creature.energy * 255.0 / 100.0 : 255; //@ а это тернарный оператор сравнения и присвоения, он по-своему коварен, но позволяет иногда избежать графомании
		pixel[0] = 0;
		pixel[1] = 0;
	}
}

VisualWorker::~VisualWorker() {
	// TODO Auto-generated destructor stub
}

