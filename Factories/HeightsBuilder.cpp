#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/ValueNoise.h"
#include "../Map/PlyConverter.h"
#include "../Map/PlyModel.h"
#include "../Map/PlyExporter.h"

void HeightsBuilder::build(World* world) {

	ValueNoise valueNoise;
	valueNoise.makeNoise(world);
	if (SimulationData::getInst()->usePLY) {
		PlyModel *model = new PlyModel;
		PlyConverter::setVertices(world, model);
		PlyConverter::setFaces(world, model);
		PlyExporter::exportPly(model);
		delete model;
	}

}
