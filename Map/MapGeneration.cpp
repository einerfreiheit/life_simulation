#include "MapGeneration.h"
#include "../SimulationData.h"
#include <iostream>
#include <random>

MapGeneration::MapGeneration() {
}

MapGeneration::~MapGeneration() {

}

float MapGeneration::smooth(const float& t) {
	return t * t * (3 - 2 * t);
}

void MapGeneration::makeNoise(World* world) {
	int height = SimulationData::getInst()->mapHeightToSet;
	int width = SimulationData::getInst()->mapWidthToSet;
	const int layersNumber = 5;
	keyValues = new float[keySize * keySize]; //@ написал new[] - задумался о delete[]

	setKeyValues();

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			float frequency = 0.1; // нужно установить зависимость между частотой и размером карты
			float amplitude = 1.0;
			for (int q = 0; q < layersNumber; q++) {

				world->map[i][j].cellHeight += getValue(i, j, frequency, amplitude);
				frequency *= 0.5;
				amplitude *= 2.0;
			}

		}
	}
}

void MapGeneration::setKeyValues() {
	srand48(2011);
	for (int i = 0; i < keySize * keySize; i++) {
		keyValues[i] = 0.5 - drand48();
	}
}

float MapGeneration::lerp(float a, float b, float possition) {
	return a * (1.0 - possition) + b * possition;
}

float MapGeneration::getValue(int y, int x, float frequency, float amplitude) {
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

	const float &point00 = keyValues[x0 + y0 * keyMask];
	const float &point10 = keyValues[x1 + y0 * keyMask];
	const float &point01 = keyValues[x0 + y1 * keyMask];
	const float &point11 = keyValues[x1 + y1 * keyMask];

	float lerpPoint1 = lerp(point00, point10, offsetX);
	float lerpPoint2 = lerp(point01, point11, offsetX);

	float lerpResult = lerp(lerpPoint1, lerpPoint2, offsetY);

	return lerpResult * amplitude;
}
