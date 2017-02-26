/*
 * cell.cpp
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */
#include "Cell.h"

#include <cstdlib>

Cell::Cell() {
}

void Cell::setCellFood() {
	this->food = rand() % 100;

}
Cell::~Cell() {

}

