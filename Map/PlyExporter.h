#ifndef MAP_PLYEXPORTER_H_
#define MAP_PLYEXPORTER_H_

#include "PlyModel.h"
#include <fstream>

class PlyExporter {
public:
	static void exportPly(PlyModel *model);
};

#endif
