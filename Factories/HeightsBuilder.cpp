#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/DiamondSquare.h"
#include "../Map/Ply.h"
#include "../Map/MapGeneration.h"

void HeightsBuilder::build(World* world) {
	//@ выбор типа генератора мира из конфига
	MapGeneration mapGen;
	mapGen.makeNoise(world);
	//DiamondSquare diamondSquare ( world );//@ переписать diamond square
	Ply ply(world);
}
