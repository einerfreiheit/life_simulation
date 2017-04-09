#include "Visualization.h"
#include <iostream>
Visualization::Visualization() {
	init();

}

Visualization::~Visualization() {

}
void Visualization::visualize(World*world){

	update(world);
	display(world);


}

void Visualization::init(){

	std::cout<<"Visualization init";

}
