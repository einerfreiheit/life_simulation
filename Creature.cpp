/*
 * worm.cpp
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#include "Creature.h"
Creature::Creature() {

	this->isHungry = false;
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

bool Creature::getHungry() {
	return this->isHungry;

}

double Creature::getEnergy() {
	return this->energy;

}
void Creature::setEnergy(double setEnergy) {
	this->energy=setEnergy;

}

Creature::~Creature() {

}

