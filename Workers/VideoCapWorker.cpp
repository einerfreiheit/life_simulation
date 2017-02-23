/*
 * VideoCapWorker.cpp
 *
 *  Created on: 23 февр. 2017 г.
 *      Author: lenovo
 */

#include "VideoCapWorker.h"
#include "CommonIncludes.h"

VideoCapWorker::VideoCapWorker(World *world) {
	this->name = "VideoCapWorker";

	writer.open("./1.avi",CV_FOURCC('M', 'J', 'P', 'G'),25.0,world->matrix.size()*10,true);

}


void VideoCapWorker::work(World *world){

	cv::Mat output;
	cv::resize(world->matrix,output,output.size(),10,10,cv::INTER_LANCZOS4);
	writer.write(output);




}

VideoCapWorker::~VideoCapWorker() {
	// TODO Auto-generated destructor stub
	writer.release();
}

