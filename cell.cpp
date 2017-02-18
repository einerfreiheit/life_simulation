/*
 * cell.cpp
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */
#include <cstdlib>
#include "cell.h"
cell::cell() {
	life_res = 0;
	blue = 0;
}
void cell::getRes() {
	this->life_res = rand() % 100;
}
int cell::getColor() {
	this->blue = 255 * this->life_res / 100;

	return blue;
}

cell::~cell() {

}

