#include "VisualWorker.h"
#include "CommonIncludes.h"
#include <iostream>



VisualWorker::VisualWorker() {
	this->name = "VisualWorker";
	visualization=new SmallWorldVisualization;


}
void VisualWorker::work(World *world) {

	visualization->visualize(world);

}


VisualWorker::~VisualWorker() {
}

