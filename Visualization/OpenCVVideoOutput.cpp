#include "OpenCVVideoOutput.h"
#include "../SimulationData.h"

OpenCVVideoOutput::OpenCVVideoOutput() {
	videoWriter = new cv::VideoWriter;
	videoWriter->open(	SimulationData::getInst()->outputPath + "./output.avi",
						CV_FOURCC('M', 'J', 'P', 'G'),
						25.0,
						cv::Size(SimulationData::getInst()->mapHeight, SimulationData::getInst()->mapWidth),
						true);

}

OpenCVVideoOutput::~OpenCVVideoOutput() {
	videoWriter->release();
	delete videoWriter;

}

void OpenCVVideoOutput::update(const cv::Mat* output) {
	cv::resize(*output, videoOutput, output->size(), 1, 1, cv::INTER_NEAREST);
	videoWriter->write(videoOutput);
}

