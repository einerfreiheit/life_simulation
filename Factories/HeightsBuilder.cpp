#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/DiamondSquare.h"
#include "../Map/Ply.h"
#include "../Map/ValueNoise.h"
#include "../Map/PlyConverter.h"
#include "../Map/PlyModel.h"
#include "../Map/PlyExporter.h"

void HeightsBuilder::build(World* world) {
	//@ выбор типа генератора мира из конфига
	ValueNoise mapGen;
	mapGen.makeNoise(world);
	//DiamondSquare diamondSquare ( world );//@ переписать diamond square

	PlyModel *model = new PlyModel;
	PlyConverter::setVertices(world, model);
	PlyConverter::setFaces(world,model);
	PlyExporter::exportPly(model);

	delete model;


}
