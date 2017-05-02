#include "SimpleVisualization.h"
#include "../SimulationData.h"
#include <cmath>
#include <iostream>


cv::Mat*   SimpleVisualization::getVisualisation()  {
    return  &visualization;
    }

void SimpleVisualization::update ( World*world ) {

    for ( int y = 0; y < world->mapHeight; y++ ) {
        for ( int x = 0; x < world->mapWidth; x++ ) {

            float  height = world->map[y][x].cellHeight;
          //  float food = world->map[y][x].food;
            double water =world->map[y][x].water;

            uchar &blue=visualization.at<uchar> ( y,3*x );
            uchar &green=visualization.at<uchar> ( y,3*x+1 );
            uchar &red=visualization.at<uchar> ( y,3*x+2 );
            uchar intensity= (height-world->minHeight ) /world->heightsRange*255;

            blue=intensity;
            green=intensity;
            red=intensity;

            if ( water>SimulationData::getInst()->soilWater ) {
                red=0;
                green=0;
                }
            }
        }


    for ( auto creature : world->creatures ) {
        int y=creature->getPosY();
        int x=creature->getPosX();
        uchar &blue=visualization.at<uchar> ( y,3*x );
        uchar &green=visualization.at<uchar> ( y,3*x+1 );
        uchar &red=visualization.at<uchar> ( y,3*x+2 );

        red = creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255;
        blue= 0;
        green = 0;
        }
    }
SimpleVisualization::SimpleVisualization() {
    visualization = cv::Mat::zeros ( SimulationData::getInst()->mapHeightToSet,
                                     SimulationData::getInst()->mapWidthToSet, CV_8UC3 );

    }
SimpleVisualization::~SimpleVisualization() {

    }

