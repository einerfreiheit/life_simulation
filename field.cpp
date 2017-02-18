/*
 * field.cpp
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */
#include <iostream>
#include "field.h"
#include <math.h>
using namespace std;
field::field() {
	init();
}

int field::getWidth() const {
	if (map.size()) {
		return map.front().size();
	}
	return 0;
}

int field::getHeight() const {
	return map.size();
}

void field::init() {
	map.resize(mapHeight);
	for (int y = 0; y < mapHeight; y++) {
		map[y].resize(mapWidth);
	}
	int worm_id = 0;
	worm_map.resize(worm_map_size);
	for (int i = 0; i < worm_map_size; i++) {
		worm_map[i].createWorm(worm_id, i, i);

	}
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			map[y][x].getRes();
		}
	}
}

void field::step() {
	wormlogic logic;
	for (int i = 0; i < worm_map.size(); i++) {

		int x = worm_map[i].getAdressX();
		int y = worm_map[i].getAdressY();

		map[y][x].life_res = logic.eat(map[y][x].life_res);

		logic.move(logic.IsHungry(map[y][x].life_res), y, x, mapHeight,
				mapWidth);
		x = logic.next_x;
		y = logic.next_y;
		worm_map[i].worm_hungry = logic.IsHungry(map[y][x].life_res);
		worm_map[i].worm_x = x;
		worm_map[i].worm_y = y;

	}

}

void field::getVis() {
	cv::Mat vis(mapHeight, mapWidth, CV_8UC3, cv::Scalar(255, 0, 0));
	for (int y = 0; y < mapHeight; y++) {
		for (int x = 0; x < mapWidth; x++) {
			cv::Vec3b bgr = vis.at<cv::Vec3b>(cv::Point(y, x));
			int v = map[y][x].getColor();
			bgr[1] = 255 - v;
			bgr[2] = 255 - v;
			vis.at<cv::Vec3b>(cv::Point(y, x)) = bgr;
		}
	}
	for (int i = 0; i < worm_map_size; i++) {
		vis.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[2] =
				255;
		vis.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[0] =
				0;
		vis.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[1] =
				0;
		if (worm_map[i].worm_hungry == true) {
			vis.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[2] =
					0;
		}

	}

	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 300, 300);
	cv::imshow("123", vis);
	cv::waitKey(10);
}

field::~field() {

}

