#ifndef MAP_PLYMODEL_H_
#define MAP_PLYMODEL_H_

#include <vector>

//@ struct для цвета и для координаты

struct vertice {
	std::vector<float> coordinates;
	std::vector<int > colors;

};
struct face {
	std::vector<int> index;
};
class PlyModel {
public:

	PlyModel();
	virtual ~PlyModel();
	void addVertice(const float&x, const float &y, const float &z);
	void addVerticeColor(int possition, const int &red, const int &green, const int &blue);
	void addFace(const std::vector<int> &verticesIndex);
	std::vector<vertice*> vertices;
	std::vector<face*> faces;
};

#endif
