#include "VideoWriterWorker.h"
#include "CommonIncludes.h"
#include <iostream>

VideoWriterWorker::VideoWriterWorker() {
	this->name = "VideoWriterWorker";

}
void VideoWriterWorker::init(World *world) {

}
void VideoWriterWorker::work(World *world) {
//	output=world->visualization;
//	cv::resize(world->visualization, output, cv::Size(), 1, 1,
//			cv::INTER_NEAREST);

	if (!initDone && !world->visualization.empty()) {

		writer.open("./1.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0,
				world->visualization.size(), true);
		initDone = true;
		std::cout<<initDone<< "init done";

	}

//	std::cout<<world->visualization.size();


//	writer.write(output);
	writer <<world->visualization;
//	output.release();
//	writer.release();
//	std::cout << writer.isOpened();



}

VideoWriterWorker::~VideoWriterWorker() {
	writer.release();
}

