#include "VisualWorker.h"
#include "CommonIncludes.h"
#include <iostream>



VisualWorker::VisualWorker() {
	this->name = "VisualWorker";
//	SimpleVisualization vis;
//	*visualization=vis;
   this->visualization=new SimpleVisualization;
   std::cout<<"VisualWorker is CReated";
//	vis.init();


}
void VisualWorker::work(World *world) {

	visualization->visualize(world);

}


VisualWorker::~VisualWorker() {
}

