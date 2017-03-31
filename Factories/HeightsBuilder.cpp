#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "HeightsBuilder.h"
HeightsBuilder::HeightsBuilder(World *world) {
	this->world = world;
	height = world->mapHeight;
	width = world->mapWidth;
	setCorners(height, width);


}

HeightsBuilder::~HeightsBuilder() {

}

void HeightsBuilder::getDepth(float &maxH, float&minH) {
	maxH = 0;
	minH = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (world->map[j][i].heightValue > maxH) {
				maxH = world->map[j][i].heightValue;
			}
			if (world->map[j][i].heightValue < minH) {
				minH = world->map[j][i].heightValue;
			}

		}

	}

}

void HeightsBuilder::setCorners(int height, int witdth) {
	int lesserSide = std::min(height, width);
	float log = std::log2(lesserSide);
	if (log - (int) log == 0) {
		step = pow(2, (int) (log) - 1);

	} else {
		step = pow(2, (int) std::floor(log));

	}
	for (int y = 0; y < height; y += step) {
		for (int x = 0; x < width; x += step) {
			world->map[y][x].heightValue = cornerHeight;

		}
	}
	step=step/firstStepDecrease;

}
bool HeightsBuilder::checkBorders(int y, int x) {
	return (x >= 0 && x < width && y >= 0 && y < height);

}

void HeightsBuilder::diamondStep(int y, int x, float range) {
	Cell &cell = world->map[y][x];
	int n = 0;
	float sumOfHeights = 0;
	if (cell.heightComputed == false) {
		int aX = x;
		int aY = y - step / 2;
		if (checkBorders(aY, aX)) {
			sumOfHeights += world->map[aY][aX].heightValue;
			n++;

		}
		int bX = x - step / 2;
		int bY = y;
		if (checkBorders(bY, bX)) {
			sumOfHeights += world->map[bY][bX].heightValue;
			n++;

		}

		int cX = x + step / 2;
		int cY = y;
		if (checkBorders(cY, cX)) {
			sumOfHeights += world->map[cY][cX].heightValue;
			n++;
		}
		int dX = x + step / 2;
		int dY = y;
		if (checkBorders(dY, dX)) {
			sumOfHeights += world->map[dY][dX].heightValue;
			n++;
		}
		cell.heightValue = sumOfHeights / n + range * rangedRandom();
		cell.heightComputed = true;
	}

}
void HeightsBuilder::DiamondSquare(float range) {
	if (step < 2)
		return;
// diamonds
	for (int i = 0; i < height - step; i += step)
		for (int j = 0; j < width - step; j += step) {
			if (!world->map[i + step / 2][j + step / 2].heightComputed) {
				float a = world->map[i][j].heightValue;
				float b = world->map[i + step][j].heightValue;
				float c = world->map[i][j + step].heightValue;
				float d = world->map[i + step][j + step].heightValue;
				world->map[i + step / 2][j + step / 2].heightValue = (a + b + c
						+ d) / 4 + rangedRandom() * range;
				world->map[i + step / 2][j + step / 2].heightComputed = true;

			}
		}
// squares*/
	for (int i = 0; i < height; i += step) {
		for (int j = 0; j < width; j += step) {

			if (checkBorders(i, j + step / 2) == true) {
				diamondStep(i, j + step / 2, range);
			}
			if (checkBorders(i + step / 2, j + step) == true) {
				diamondStep(i + step / 2, j + step, range);

			}
			if (checkBorders(i + step, j + step / 2) == true) {
				diamondStep(i + step, j + step / 2, range);

			}
			if (checkBorders(i + step / 2, j) == true) {
				diamondStep(i + step / 2, j, range);

			}

		}
	}
	step /= 2;
	DiamondSquare(range / smooth);

}
float HeightsBuilder::rangedRandom() {
	return 2*(float) rand() / RAND_MAX-1;

}

