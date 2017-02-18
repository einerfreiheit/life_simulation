/*
 * worm.cpp
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#include "worm.h"
worm::worm() {
	worm_id=0;
	worm_x=0;
	worm_y=0;
	worm_hungry=false;



}
int  worm::getAdressX(){

	return this->worm_x;

}
int  worm::getAdressY(){
	return this->worm_y;

}
void worm::createWorm(int worm_id,int worm_y,int worm_x){
	this->worm_id= worm_id;
	this->worm_x=worm_x;
	this->worm_y=worm_y;



}



worm::~worm() {

}

