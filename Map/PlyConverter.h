#ifndef MAP_PLYCONVERTER_H_
#define MAP_PLYCONVERTER_H_

#include "../World.h"
#include "PlyModel.h"

class PlyConverter {
public:

	static void buildPLYModel(World *world, PlyModel * model);

	static void setVertices(World *world, PlyModel *model);
	static void setFaces(World *world, PlyModel *model);
	static bool setColors;


};

#endif
