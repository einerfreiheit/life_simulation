/*
 * cell.cpp
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */
#include "Cell.h"

#include <cstdlib>

cell::cell()
{
    life_res = 0;
}
void cell::getRes()
{
    this->life_res = rand() % 70;
}


cell::~cell()
{

}

