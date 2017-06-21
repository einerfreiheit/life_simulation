#include "PlyExporter.h"
#include "../SimulationData.h"
#include <iostream>
using namespace std;
void PlyExporter::exportPly(PlyModel *model) {

	std::string outputPath = SimulationData::getInst()->outputPath + "output.ply";
	std::ofstream out(outputPath);
	out << "ply" << std::endl;
	out << "format ascii 1.0" << std::endl;
	out << "element vertex";
	out << ' ' << model->vertices.size() << std::endl;
	out << "property float x" << std::endl;
	out << "property float y" << std::endl;
	out << "property float z" << std::endl;
	out << "property uchar red" << std::endl;
	out << "property uchar green" << std::endl;
	out << "property uchar blue" << std::endl;
	out << "element face";
	out << ' ' << model->faces.size() << std::endl;
	out << "property list uchar int vertex_index" << std::endl;
	out << "end_header" << std::endl;

	for (int i = 0; i < model->vertices.size(); i++) {
		for (auto coordinate : model->vertices[i]->coordinates) {
			out << coordinate << ' ';
		}
		for (auto color : model->vertices[i]->colors) {
			out << color << ' ';
		}
		out << std::endl;

	}
	for (int i = 0; i < model->faces.size(); i++) {

		out << model->faces[i]->index.size() << ' ';
		for (auto index : model->faces[i]->index) {
			out << index << ' ';
		}

		out << std::endl;
	}
}

