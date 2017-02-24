/*
 * worm.cpp
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#include "Creature.h"
worm::worm()
{
    worm_x = 0;
    worm_y = 0;
   worm_hungry = false;
   worm_energy=50.0;


}
int  worm::getAdressX()
{

    return this->worm_x;

}
int  worm::getAdressY()
{
    return this->worm_y;

}
void worm::createWorm( int worm_y, int worm_x)
{
    this->worm_x = worm_x;
    this->worm_y = worm_y;
    this->worm_energy = 50.0;



}



worm::~worm()
{

}

