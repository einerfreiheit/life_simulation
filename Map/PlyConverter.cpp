#include "PlyConverter.h"
#include "../SimulationData.h"

void PlyConverter::setVertices(World *world, PlyModel *model) {
	int height = SimulationData::getInst()->mapHeightToSet;
	int width = SimulationData::getInst()->mapWidthToSet;
	double maxHeight = world->map[0][0].height;
	double minHeight = world->map[0][0].height;
	for (int i = 0; i < world->map.size(); i++) {
		for (int j = 0; j < world->map[0].size(); j++) {
			double height = world->map[i][j].height;
			maxHeight = std::max(maxHeight, height);
			minHeight = std::min(minHeight, height);
		}
	}
	
	if (std::abs(maxHeight - minHeight) < 0.00001) {
		throw std::runtime_error("float map, all heights are equal");
	}
	int possition = 0;//@ ss
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int color = 255 * (world->map[y][x].height - minHeight) / (maxHeight - minHeight);//@ отпимайз
			model->addVertice(x, y, world->map[y][x].height);
			model->addVerticeColor(possition,  color, (int)(color / 2),0);
			possition++;
		}
	}

}
void PlyConverter::setFaces(World *world, PlyModel *model) {
	int height = SimulationData::getInst()->mapHeightToSet;
	int width = SimulationData::getInst()->mapWidthToSet;

	for (int y = 0; y < height-1; y++) {
		for (int x = 0; x < width-1; x++) {
			std::vector<int> index;
			index.push_back(x + y * width);//@ в ply нумерация с 0 или с 1?
			index.push_back(x + 1 + y * width);
			index.push_back((y + 1) * width + x + 1);
			index.push_back((y + 1) * width + x);
			model->addFace(index);
		}
	}
}
