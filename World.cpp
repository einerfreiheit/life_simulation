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

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            map[y][x].getRes();
        }
    }
    matrix = cv::Mat (mapHeight,mapWidth, CV_8UC3);
    matrix= cv::Scalar(255,0,0);
}

