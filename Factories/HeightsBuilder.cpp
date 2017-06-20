#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/DiamondSquare.h"
#include "../Map/Ply.h"
#include "../Map/ValueNoise.h"

void HeightsBuilder::build(World* world) {
	//@ выбор типа генератора мира из конфига
	ValueNoise mapGen;
	mapGen.makeNoise(world);
	//DiamondSquare diamondSquare ( world );//@ переписать diamond square
	Ply ply(world);
}
