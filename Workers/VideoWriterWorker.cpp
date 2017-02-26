/*
 * VideoCapWorker.cpp
 *
 *  Created on: 23 февр. 2017 г.
 *      Author: lenovo
 */

#include "VideoWriterWorker.h"

#include "CommonIncludes.h"

VideoWriterWorker::VideoWriterWorker(World *world) {
	this->name = "VideoOuputWorker";//@ надо указывать актуальное имя класса VideoWriterWorker, чтобы потом было проще разбираться, где упало

	writer.open("./1.avi",CV_FOURCC('M','J','P','G'),25.0,world->matrix.size()*10,true);

}


void VideoWriterWorker::work(World *world){

	cv::Mat output;
	cv::resize(world->matrix,output,output.size(),10,10, cv::INTER_NEAREST);
	writer.write(output);

}

VideoWriterWorker::~VideoWriterWorker() {
	writer.release();
}

