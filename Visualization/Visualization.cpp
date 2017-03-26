#include "Visualization.h"

Visualization::Visualization() {

}

Visualization::~Visualization() {

}

void Visualization::visualize(World *world){
	computeImage(world);
	showImage(world);
}
