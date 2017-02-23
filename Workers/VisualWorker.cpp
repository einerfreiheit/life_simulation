/*
 * VisualWorker.cpp
 *
 *  Created on: 21 февр. 2017 г.
 *      Author: lenovo
 */

#include "VisualWorker.h"
#include "CommonIncludes.h"
#include <iostream>

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";

}
void VisualWorker::work(World *world)
{
	   getImage(world);
	   showImage(world);


}

void VisualWorker::showImage(World *world){
	cv::namedWindow("123", CV_WINDOW_NORMAL);
	cv::resizeWindow("123", 300, 300);
    cv::imshow("123", world->matrix);
    cv::waitKey(10);


}

void VisualWorker::getImage(World *world){
	std::vector<worm> &worm_map = world->worm_map;
	std::vector<std::vector<cell> > &map = world->map;
	const int &mapHeight =world->mapHeight;
	const int &mapWidth=world->mapWidth;


	 for (int y = 0; y < mapHeight; y++) {
	        for (int x = 0; x < mapWidth; x++) {
	        	world->matrix.at<cv::Vec3b>(cv::Point(y, x))[1]=255 - map[y][x].getColor();
				world->matrix.at<cv::Vec3b>(cv::Point(y, x))[2] =255 - map[y][x].getColor();
				world->matrix.at<cv::Vec3b>(cv::Point(y, x))[0]= 255;

	        }
	    }
	    for (int i = 0; i < world->worm_map_size; i++) {
	    	world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[2] =
	            255;
	    	world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[0] =
	            0;
	    	world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[1] =
	            0;
	        if (worm_map[i].worm_hungry == true) {
	        	world->matrix.at<cv::Vec3b>(cv::Point(worm_map[i].worm_y, worm_map[i].worm_x))[2] =
	                0;
	        }

	    }

}

VisualWorker::~VisualWorker() {
	// TODO Auto-generated destructor stub
}

