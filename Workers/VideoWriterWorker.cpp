#include "VideoWriterWorker.h"
#include "CommonIncludes.h"

VideoWriterWorker::VideoWriterWorker() {
	this->name = "VideoWriterWorker";

}
void VideoWriterWorker::init(World *world) {
	if (!initDone&&world->visualization.size>0) {
		writer.open("./1.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0,
				world->visualization.size() * 10, true);
		initDone=true;
	}

}
void VideoWriterWorker::work(World *world) {
	init(world);
	cv::resize(world->visualization, output, output.size(), 10, 10,
			cv::INTER_NEAREST);
	writer.write(output);

}

VideoWriterWorker::~VideoWriterWorker() {
	writer.release();
}

