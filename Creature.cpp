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
void Creature::setEnergy(double setEnergy) {//@ не очень здорово называть переменную так же, как называется метод
	this->energy=setEnergy; //@ и переменная - это нечто, что-то, = существительное
	//@ а setEnergy в свою очередь звучит как глагол (так звучат методы - сделай что-то)
	//@ поэтому такое название не очень удачное
	//@ если не хочется придумывать названий, можешь писать this->energy = _energy;
	//@ другие варианты: toSet, energyToSet, value, quantity - заметь, все звучат как существительные

}

Creature::~Creature() {

}

