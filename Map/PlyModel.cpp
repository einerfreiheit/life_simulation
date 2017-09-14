#include "PlyModel.h"

PlyModel::PlyModel() {

}

PlyModel::~PlyModel() {
	if (vertices.size()){
		for (int i=0;i<vertices.size();i++){
			delete vertices[i];
		}
	}
	if (indices.size()){
		for (int i=0;i<indices.size();i++){
			delete indices[i];
		}
	}

}



void PlyModel::addCellVertices(Cell *cell, const float& minHeight, const float &heightDepth) {
	vertexData *data = new vertexData;

	data->x = cell->x;
	data->y = cell->y;
	data->z = cell->heights[0][0];
	uchar color = 255 * (data->z - minHeight) / heightDepth;
	data->red = color;
	data->blue = color / 2;
	data->green = 0;
	vertices.push_back(data);

}

void PlyModel::addIndices(World *world) {

	int height = world->map.size();
	int width = world->map[0].size();
	for (int y = 0; y < height - 1; y++) {
		for (int x = 0; x < width - 1; x++) {

			cellIndices * newIndices = new cellIndices;
			newIndices->values.push_back(x + y * width);
			newIndices->values.push_back(x + 1 + y * width);
			newIndices->values.push_back((y + 1) * width + x + 1);
			newIndices->values.push_back((y + 1) * width + x);
			indices.push_back(newIndices);
		}
	}
}

