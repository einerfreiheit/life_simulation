#include "World.h"
#include <iostream>
#include <math.h>
using namespace std;

World::World()
{
    init();
}

World::~World()
{

}

int World::getWidth() const
{
    if (map.size()) {
        return map.front().size();
    }
    return 0;
}

int World::getHeight() const
{
    return map.size();
}

void World::init()
{
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

void World::getVis()
{
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
