#include "PlyConverter.h"
#include "../SimulationData.h"


void PlyConverter::buildPLYModel(World *world, PlyModel *model) {
	model->addIndices(world);

	int height = world->map.size();
	int width = world->map[0].size();

	float maxHeight = world->map[0][0].height;
	float minHeight = world->map[0][0].height;

	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			float height = world->map[i][j].height;
			maxHeight = std::max(maxHeight, height);
			minHeight = std::min(minHeight, height);
		}
	}
	float heightDepth = maxHeight-minHeight;

	if (std::abs(maxHeight - minHeight) < 0.00001) {
		throw std::runtime_error("float map, all heights are equal");
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			model->addCellVertices(world->getCell(y,x),minHeight,heightDepth);
		}
	}

}


