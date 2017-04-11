#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_
#include "WorldWorker.h"
#include "../Visualization/SimpleVisualization.h"
#include "SubWorkers/VisualSubWorker.h"


#include <vector>

class VisualWorker: public WorldWorker {
public:
	VisualWorker();
	virtual ~VisualWorker();
	void work(World *world) override;
private:
	SimpleVisualization *visual;
	std::vector<VisualSubWorker *> visualSubWorkers;


};

#endif
