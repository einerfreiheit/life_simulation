/*
 * wormlogic.cpp

 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */
#include <cstdlib>
#include "wormlogic.h"

wormlogic::wormlogic() {
	hungry = false;
	way = -1;
	next_x = 0;
	next_y = 0;

}
double wormlogic::eat(double food) {
	if (food > 10) {
		food = food - 10;
	} else
		food = 0.0;
	return food;
}

bool wormlogic::IsHungry(double food) {
	if (food == 0)
		hungry = true;

	else
		hungry = false;
	return hungry;
}
void wormlogic::move(bool hungry, int y, int x, int size_y, int size_x) {
	next_x = x;
	next_y = y;
	if (hungry == true) {
		way = rand() % 4;

		if (way == 0) {
			if (y > 0)
				next_y = y - 1;
			else
				next_y = y + 1;
		}
		if (way == 1) {
			if (y < size_y)
				next_y = y + 1;
			else
				next_y = y - 1;
		}
		if (way == 2) {
			if (x > 0)
				next_x = x - 1;
			else
				next_x = x + 1;
		}
		if (way == 3) {
			if (x < size_x)
				next_x = x + 1;
			else
				next_x = x - 1;
		}

	}

}

wormlogic::~wormlogic() {
	// TODO Auto-generated destructor stub
}

