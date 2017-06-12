#include "GeneticsUtils.h"
#include <stdlib.h>

float GeneticsUtils::rangedRandom(float minValue, float maxValue) {
	float value = (float) rand() / RAND_MAX;
	return minValue + (maxValue - minValue) * value;
}
