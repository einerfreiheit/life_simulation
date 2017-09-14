#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_

#include "WorldWorker.h"
#include "../Visualization/OpenCVOutput.h"
#include "../Visualization/OpenCVData.h"

#include <vector>

class VisualWorker: public WorldWorker {
public:
	VisualWorker(World *world);
	virtual ~VisualWorker();
	void work(World *world) override;
private:
	OpenCVData *data;
	std::vector<OpenCVOutput*> output;
};

#endif
