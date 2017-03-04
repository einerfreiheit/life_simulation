/*
 * VideoCapWorker.cpp
 *
 *  Created on: 23 февр. 2017 г.
 *      Author: lenovo
 */

#include "VideoWriterWorker.h"

#include "CommonIncludes.h"

VideoWriterWorker::VideoWriterWorker(World *world) {
	this->name = "VideoWriterWorker";

	writer.open("./1.avi",CV_FOURCC('M','J','P','G'),25.0,world->visualization.size()*10,true);

}


void VideoWriterWorker::work(World *world){

	cv::Mat output;
	cv::resize(world->visualization,output,output.size(),10,10, cv::INTER_NEAREST);
	writer.write(output);

}

VideoWriterWorker::~VideoWriterWorker() {
	writer.release();
}

