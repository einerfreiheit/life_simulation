#include "VisualWorker.h"
#include <iostream>


#include "../Visualization/SimpleDisplay.h"
#include "../Visualization/SimpleVideoRecord.h"

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";

	simpleVisualization = new SimpleVisualization;

	visualOutput.push_back(new SimpleVideoRecord);
	visualOutput.push_back(new SimpleDisplay);

}
void VisualWorker::work(World *world) {
	simpleVisualization->update(world);

	for (VisualOutput * output : visualOutput) {
		output->update(simpleVisualization->getVisualisation());
	}

}

VisualWorker::~VisualWorker() {

}

