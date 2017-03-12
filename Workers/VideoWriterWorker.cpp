#include "VideoWriterWorker.h"
#include "CommonIncludes.h"

VideoWriterWorker::VideoWriterWorker() {
	this->name = "VideoWriterWorker";
	this->isAvailable = SimulationData::getInst()->VideoWriterWorkerIsAvailable;
	World *world = SimulationData::getInst()->world;

	writer.open("./1.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0,
			world->visualization.size() * 10, true);//@ лучше сделать отложенную инициализацию записывалки видео
//@ а вдруг мы world->visualization не определим?
}

void VideoWriterWorker::work(World *world) {

	cv::Mat output;
	cv::resize(world->visualization, output, output.size(), 10, 10,
			cv::INTER_NEAREST);
	writer.write(output);

}

VideoWriterWorker::~VideoWriterWorker() {
	writer.release();
}

