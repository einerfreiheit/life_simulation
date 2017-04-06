#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "SimulationData.h"

#include "HeightsBuilder.h"//@ добавить перевод строки
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
			if (world->map[j][i].heightValue > maxH) {//@ 4 раза пишется длинное выражение world->map[j][i].heightValue
				maxH = world->map[j][i].heightValue;//@ лучше написать height = world->map[j][i].heightValue; и уже плясать от этого
			}
			if (world->map[j][i].heightValue < minH) {
				minH = world->map[j][i].heightValue;
			}

		}

	}

}

void HeightsBuilder::setCorners() {
	int lesserSide = std::min(height, width);
	float log = std::log2(lesserSide);//@ очень плохое название для переменной - в стандратных функциях есть такая функция log
	if (log - (int) log == 0) {//@ странное выражение, дробные значения сравнивают с помощью какого-то эпсилона:
		step = pow(2, (int) (log) - 1);//@ if (std::abs(floatValue) < 0.0001) ... <- вот так правильно, потому что дробные переменные могут накапливать ошибку, но обычно ошибка небольшая. Легко может так получится, что ты вроде как должен получить после преобразований целое число, но получаешь что-то другое из-за неточности нецелых типов

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
}//@ перевод строки?
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

	for (int i = 0; i <= height; i += step) {//@ вот тут уже как минимум выход за границы массива может быть
		for (int j = step / 2; j <= width - step / 2; j += step) {
			diamondStep(i, j, range);
			std::cout << i << j << std::endl;
		}
	}
	for (int i = step / 2; i <= height - step / 2; i += step) {
		for (int j = 0; j <= width; j += step) {//@ и тут тоже

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

