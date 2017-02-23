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
	matrix = cv::Mat (mapHeight,mapWidth, CV_8UC3);
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

