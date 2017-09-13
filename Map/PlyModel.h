#ifndef MAP_PLYMODEL_H_
#define MAP_PLYMODEL_H_

#include <vector>
#include "../World.h"

struct vertexData {
	float x;
	float y;
	float z;
	int red;
	int green;
	int blue;

};
struct cellIndices {
	std::vector<int> values;
};

class PlyModel {
public:

	PlyModel();
	virtual ~PlyModel();

	void addCellVertices(Cell *cell, const float &minHeight, const float &heightDepth);
	void addIndices(World *world);
	std::vector<cellIndices*> indices;
	std::vector<vertexData*> vertices;
};

#endif
