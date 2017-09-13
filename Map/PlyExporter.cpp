#include "PlyExporter.h"
#include "../SimulationData.h"
#include <iostream>

void PlyExporter::exportPly(PlyModel *model) {

	std::string outputPath = SimulationData::getInst()->outputPath + "output.ply";
	std::ofstream out(outputPath);
	out << "ply" << std::endl;
	out << "format ascii 1.0" << std::endl;
	out << "element vertex";
	out << " " << model->vertices.size() << std::endl;
	out << "property float x" << std::endl;
	out << "property float y" << std::endl;
	out << "property float z" << std::endl;
	out << "property uchar red" << std::endl;
	out << "property uchar green" << std::endl;
	out << "property uchar blue" << std::endl;
	out << "element face";
	out << " " << model->indices.size() << std::endl;
	out << "property list uchar int vertex_index" << std::endl;
	out << "end_header" << std::endl;

	for (auto vertex : model->vertices) {

		out << vertex->x << " " << vertex->y << " " << vertex->z << " " << vertex->red << " " << vertex->blue << " "
				<< vertex->green << " " << std::endl;
	}
	for (auto index : model->indices) {
		out << index->values.size() << " ";
		for (auto value : index->values) {
			out << value << " ";
		}
		out << std::endl;
	}

	out.close();

}
