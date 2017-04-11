#include "VisualWorker.h"
#include <iostream>


#include"SubWorkers/VisualDisplayWorker.h"
#include"SubWorkers/VisualVideoWorker.h"

VisualWorker::VisualWorker() {
	this->name = "VisualWorker";
	this->visual = new SimpleVisualization;

	visualSubWorkers.push_back(new VisualDisplayWorker);
	visualSubWorkers.push_back(new VisualVideoWorker);



}
void VisualWorker::work(World *world) {
	visual->update(world);

	for (VisualSubWorker * subWorker : visualSubWorkers) {
		subWorker->work(visual->getVisualisation());
	}

}

VisualWorker::~VisualWorker() {

}

