#ifndef PLY_H
#define PLY_H

#include "World.h"
#include <fstream>
#include <locale>

//@ сделать в общем видел ply-модель
//@ сделать конвертер мира в ply-модель
class Ply {
public:
	Ply(World *world);
	~Ply();
	void buildVertices(World *world, std::ofstream & out);
	std::ofstream* oPtr;
	void buildFaces(World *world, std::ofstream &out);
	void buildHeader(std::ofstream &out);

};

#endif
