/*
 * worm.cpp
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#include "Creature.h"
Creature::Creature() {


	energy = 0.0;
	x = 0;
	y = 0;

}

void Creature::setPosX(int setX) {

	this->x = setX;
}
void Creature::setPosY(int setY) {
	this->y = setY;

}
int Creature::getPosX() {

	return this->x;
}
int Creature::getPosY() {
	return this->y;

}

bool Creature::isHungry() {
	if (this->energy <=lowEnergyLevel){
		return true;

	}
	else
		return false;


}

double Creature::getEnergy() {
	return this->energy;

}
void Creature::setEnergy(double energyToSet) {
	this->energy = energyToSet;

}

Creature::~Creature() {

}

