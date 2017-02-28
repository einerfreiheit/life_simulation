/*
 * worm.cpp
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#include "Creature.h"
Creature::Creature() {


	this->energy = 50.0;
	this->x = 0;
	this->y = 0;

}
void Creature::setPosX(int setX) {

	x = setX;
}
void Creature::setPosY(int setY) {
	y = setY;

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

