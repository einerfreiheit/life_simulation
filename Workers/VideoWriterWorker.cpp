#include "VideoWriterWorker.h"
#include "CommonIncludes.h"

VideoWriterWorker::VideoWriterWorker() {
	this->name = "VideoWriterWorker";

}
void VideoWriterWorker::init(World *world) {
	writer.open("./1.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0,
			world->visualization.size() * 10, true);

}
void VideoWriterWorker::work(World *world) {
	bool initDone;
	if (!initDone) {
		init(world);
		initDone = true;
	}
	cv::Mat output;
	cv::resize(world->visualization, output, output.size(), 10, 10,
			cv::INTER_NEAREST);
	writer.write(output);

}

VideoWriterWorker::~VideoWriterWorker() {
	writer.release();
}

