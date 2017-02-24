/*
 * ResWorker.cpp
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#include "ResWorker.h"
#include <cstdlib>


ResWorker::ResWorker() {
	this->name = "ResWorker";
}

void ResWorker::work(World *world){
	mapHeight =world->mapHeight;//@ старое-доброе присваивание в поле класса, лишь усложняющее понимание всего кода
	mapWidth = world->mapWidth;
	rand_x=rand()%mapWidth;
	rand_y=rand()%mapHeight;
	if (world->map[rand_y][rand_x].life_res<=90)
		world->map[rand_y][rand_x].life_res=world->map[rand_y][rand_x].life_res+0.0;//волшебная константа прироста ресурса должна быть вынесена куда-то на видное место, мб в хедер


}
ResWorker::~ResWorker() {
	// TODO Auto-generated destructor stub
}

