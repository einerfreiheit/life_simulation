#include "VisualWorker.h"
#include "../Visualization/OpenCVVideoOutput.h"
#include "../Visualization/OpenCVDisplay.h"

VisualWorker::VisualWorker(World *world) {
	this->name = "VisualWorker";

	data = new OpenCVData(world);
	if (SimulationData::getInst()->videoRecord) {
		output.push_back(new OpenCVVideoOutput);
	}
	if (SimulationData::getInst()->displayOutput) {
		output.push_back(new OpenCVDisplay);
	}

}

void VisualWorker::work(World *world) {
	data->update(world);
	for (auto unit: output){
		unit->update(data->getVisiulization());
	}

}

VisualWorker::~VisualWorker() {

}

