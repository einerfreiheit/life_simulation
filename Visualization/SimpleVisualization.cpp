#include "SimpleVisualization.h"
#include "../SimulationData.h"
#include <iostream>


 cv::Mat*   SimpleVisualization::getVisualisation()  {

    return  &visualization;
    }

void SimpleVisualization::update ( World*world ) {
    float depth = world->heightsRange;

    for ( int y = 0; y < world->mapHeight; y++ ) {
        for ( int x = 0; x < world->mapWidth; x++ ) {

            float  height = world->map[y][x].cellHeight;
            float food = world->map[y][x].food;
	    double water =world->map[y][x].water;
            cv::Vec3b &pixel = visualization.at<cv::Vec3b> ( y, x );

            int color;
            if ( height>=0 ) {
                color =  255* height / ( world->maxHeight );
                pixel[0] = color;
                pixel[1] = color;
                pixel[2] = color;

                }

            else {

//                 color =((world->minHeight -height)/world->minHeight)*150;
	        color =std::max(255+ water*255/world->minHeight, 25.0);
                pixel[0]=color;
                pixel[1]=0;
                pixel[2]=0;

                }
            }
    }
        for ( auto creature : world->creatures ) {
            cv::Vec3b &pixel = visualization.at<cv::Vec3b> ( creature->getPosY(),
                               creature->getPosX() );
            pixel[2] =
                creature->isHungry() ? creature->energy * 255.0 / 100.0 : 255;
            pixel[0] = 0;
            pixel[1] = 0;
            }
        }
    SimpleVisualization::SimpleVisualization() {
        visualization = cv::Mat::zeros ( SimulationData::getInst()->mapHeightToSet,
                                         SimulationData::getInst()->mapWidthToSet, CV_8UC3 );

        }
    SimpleVisualization::~SimpleVisualization() {

        }

