#include "../SimulationData.h"
#include <iostream>
#include <random>
#include <cmath>
#include "ValueNoise.h"

ValueNoise::ValueNoise() {
	keyValues = new float[keySize * keySize];

}

ValueNoise::~ValueNoise() {
	delete[] keyValues;

}

float ValueNoise::smooth(const float& t) {
	return t * t * (3 - 2 * t);
}

void ValueNoise::makeNoise(World* world) {
	int height = SimulationData::getInst()->mapHeight;
	int width = SimulationData::getInst()->mapWidth;
	const int layersNumber = 5;
	float frequency = 0.3;
	float amplitude = 1.0;

	setKeyValues();

	float heightMap[(height + 1) * (width + 1)] = { 0.0 };
	for (int i = 0; i < (height + 1); i++) {
		for (int j = 0; j < (width + 1); j++) {
			frequency = 0.3;
			amplitude = 1.0;
			for (int q = 0; q < layersNumber; q++) {
				heightMap[j + i * (width + 1)] += getValue(i, j, frequency, amplitude);
				frequency *= 0.5;
				amplitude *= 2.0;
			}

		}
	}

	for (int i = 0; i < (height); i++) {
		for (int j = 0; j < (width); j++) {
			world->getCell(i, j)->heights[0][0] = heightMap[j + (width + 1) * i];
			world->getCell(i, j)->heights[0][1] = heightMap[j + (width + 1) * i + 1];
			world->getCell(i, j)->heights[1][0] = heightMap[j + (width + 1) * i + (width + 1)];
			world->getCell(i, j)->heights[1][1] = heightMap[j + (width + 1) * i + width + 2];

		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			frequency = 0.3;
			amplitude = 1.0;
			for (int q = 0; q < layersNumber; q++) {

				world->map[i][j].height += getValue(i, j, frequency, amplitude);
				frequency *= 0.5;
				amplitude *= 2.0;
			}

		}

	}


}

void ValueNoise::setKeyValues() {
	srand48(2011);
	for (int i = 0; i < keySize * keySize; i++) {
		keyValues[i] = 0.5 - drand48();
	}
}

float ValueNoise::lerp(float a, float b, float possition) {
	return a * (1.0 - possition) + b * possition;
}

float ValueNoise::getValue(int y, int x, float frequency, float amplitude) {
	float ky = y * frequency;
	float kx = x * frequency;

	int iy = (int) ky;
	int ix = (int) kx;

	float offsetX = smooth(kx - ix);
	float offsetY = smooth(ky - iy);

	int y0 = iy & keyMask;
	int y1 = (iy + 1) & keyMask;
	int x0 = ix & keyMask;
	int x1 = (ix + 1) & keyMask;

	const float &point00 = keyValues[x0 + y0 * keySize];
	const float &point10 = keyValues[x1 + y0 * keySize];
	const float &point01 = keyValues[x0 + y1 * keySize];
	const float &point11 = keyValues[x1 + y1 * keySize];

	float lerpPoint1 = lerp(point00, point10, offsetX);
	float lerpPoint2 = lerp(point01, point11, offsetX);

	float lerpResult = lerp(lerpPoint1, lerpPoint2, offsetY);

	return lerpResult * amplitude;
}
