#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "SimulationData.h"

#include "HeightsBuilder.h"
HeightsBuilder::HeightsBuilder(World *world) {
	this->world = world;
	height = world->mapHeight;
	width = world->mapWidth;
	firstStepDecrease = SimulationData::getInst()->firstStepDecrease;
	smooth = SimulationData::getInst()->smooth;
	cornerHeight = SimulationData::getInst()->cornerHeight;
	setCorners();

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

void HeightsBuilder::setCorners() {
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
	step = step / firstStepDecrease;

}


void HeightsBuilder::diamondStep(int y, int x, float range) {
	Cell &cell = world->map[y][x];
	int n = 0;
	float sumOfHeights = 0;

	for (int j = x - step / 2; j <= x + step / 2; j += step) {
		if (j >= 0 && j <= width - 1) {
			sumOfHeights += world->map[y][j].heightValue;
			n++;
		}
	}
	for (int i = y - step / 2; i <= y + step / 2; i += step) {
		if (i >= 0 && i <= height - 1) {
			sumOfHeights += world->map[i][x].heightValue;
			n++;
		}
	}
	cell.heightValue = sumOfHeights / n + range * rangedRandom();
}
void HeightsBuilder::DiamondSquare(float range) {
	if (step < 2)
		return;
// diamonds
	for (int i = 0; i < height - step; i += step)
		for (int j = 0; j < width - step; j += step) {

			float a = world->map[i][j].heightValue;
			float b = world->map[i + step][j].heightValue;
			float c = world->map[i][j + step].heightValue;
			float d = world->map[i + step][j + step].heightValue;
			world->map[i + step / 2][j + step / 2].heightValue = (a + b + c + d)
					/ 4 + rangedRandom() * range;

		}
// squares*/

	for (int i = 0; i <= height; i += step) {
		for (int j = step / 2; j <= width - step / 2; j += step) {
			diamondStep(i, j, range);
			std::cout << i << j << std::endl;
		}
	}
	for (int i = step / 2; i <= height - step / 2; i += step) {
		for (int j = 0; j <= width; j += step) {

			diamondStep(i, j, range);
			std::cout << i << j << std::endl;

		}
	}

	step /= 2;
	DiamondSquare(range / smooth);

}
float HeightsBuilder::rangedRandom() {
	return 2 * (float) rand() / RAND_MAX - 1;

}

