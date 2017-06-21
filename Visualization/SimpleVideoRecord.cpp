#include "SimpleVideoRecord.h"
#include "../SimulationData.h"
#include <iostream>

SimpleVideoRecord::SimpleVideoRecord() {
	output = new cv::Mat;
	writer.open(SimulationData::getInst()->outputPath + "./output.avi",
				CV_FOURCC('M', 'J', 'P', 'G'),
				25.0,
				cv::Size(SimulationData::getInst()->mapHeightToSet, SimulationData::getInst()->mapWidthToSet),
				true);
}

SimpleVideoRecord::~SimpleVideoRecord() {
	delete output;
}

void SimpleVideoRecord::update(const cv::Mat* visualization) {
	cv::resize(*visualization, *output, visualization->size(), 1, 1, cv::INTER_NEAREST);

	writer.write(*output);
	writer.release();
	output->release();

}

void SimpleVideoRecord::update(World *world) {
}

