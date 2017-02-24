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

	writer.open("./1.avi",CV_FOURCC('M','J','P','G'),25.0,world->matrix.size()*10,true);

}


void VideoCapWorker::work(World *world){

	cv::Mat output;
	cv::resize(world->matrix,output,output.size(),10,10, cv::INTER_NEAREST);//@ вместо output.size() следовало бы написать просто cv::Size()
	//@ также ты не угадал с методом интерполяции картинки при ресайзе, поэтому видео генерилось странное
	//@ почитай про методы интерполяции и подумай, почему линейная интерполяция, к примеру, превращала видос в нечто некрасивое, а "ближайший сосед" оказался тем, что нужно
	writer.write(output);

}

VideoCapWorker::~VideoCapWorker() {
	// TODO Auto-generated destructor stub
	writer.release();
}

