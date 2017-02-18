/*
 * bacterial.cpp
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */
#include "field.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

int main() {
	field b;
	for (;;) {
		b.getVis();
		b.step();
		usleep(500000);
	}
	return 0;
}

