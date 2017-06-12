#include "VisualWorker.h"
#include <iostream>

#include "../Visualization/SimpleDisplay.h"
#include "../Visualization/SimpleVideoRecord.h"

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";

	simpleVisualization = new SimpleVisualization;
	if (SimulationData::getInst()->videoRecord) {
		outputUnits.push_back(new SimpleVideoRecord);
	}
	if (SimulationData::getInst()->displayOutput) {
		outputUnits.push_back(new SimpleDisplay);
	}
}

void VisualWorker::work(World *world) {
	simpleVisualization->update(world);

	for (OpenCvVisualization * output : outputUnits) {

		output->update(simpleVisualization->getVisualisation());
	}

}

VisualWorker::~VisualWorker() {

}

