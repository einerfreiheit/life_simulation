#include "PlyModel.h"

PlyModel::PlyModel() {
	std::vector<vertice*> vertices;//@ useless
	std::vector<face*> faces;
}

PlyModel::~PlyModel() {
	if (!vertices.empty()) {
		for (int i = 0; i < vertices.size(); i++) {
			delete vertices[i];
		}
	}
	if (!faces.empty()) {
		for (int i = 0; i < faces.size(); i++) {
			delete faces[i];
		}
	}

}

void PlyModel::addVertice(const float &x, const float &y, const float &z) {
	vertice* vert = new vertice;
	vert->coordinates.push_back(x);
	vert->coordinates.push_back(y);
	vert->coordinates.push_back(z);
	vertices.push_back(vert);

}
void PlyModel::addVerticeColor(int possition, const int &red, const int &green, const int &blue) {

	vertices[possition]->colors.push_back(red);
	vertices[possition]->colors.push_back(green);
	vertices[possition]->colors.push_back(blue);
}

void PlyModel::addFace(const std::vector<int> &verticesIndex) {
	face *newFace = new face;
	newFace->index = verticesIndex;
	faces.push_back(newFace);
}
