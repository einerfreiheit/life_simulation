/*
 * VisualWorker.cpp
 *
 *  Created on: 21 февр. 2017 г.
 *      Author: lenovo
 */

#include "VisualWorker.h"
#include "CommonIncludes.h"

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";
}
void VisualWorker::work(World *world)
{
	std::vector<worm> &worm_map = world->worm_map;
	std::vector<std::vector<cell> > &map = world->map;

    cv::Mat vis(world->mapHeight,world->mapWidth, CV_8UC3, cv::Scalar(255, 0, 0));
    for (int y = 0; y < world->mapHeight; y++) {
        for (int x = 0; x < world->mapWidth; x++) {
            cv::Vec3b bgr = vis.at<cv::Vec3b>(cv::Point(y, x));
            int v = map[y][x].getColor();
            bgr[1] = 255 - v;
            bgr[2] = 255 - v;
            vis.at<cv::Vec3b>(cv::Point(y, x)) = bgr;
        }
    }
    for (int i = 0; i < world->worm_map_size; i++) {
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


VisualWorker::~VisualWorker() {
	// TODO Auto-generated destructor stub
}

