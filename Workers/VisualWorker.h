#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_
#include "WorldWorker.h"
#include "../Visualization/SmallWorldVisualization.h"
#include "../Visualization/Visualization.h"


class VisualWorker : public WorldWorker {
public:
	VisualWorker();
	virtual ~VisualWorker();
	void work (World *world) override;
	Visualization *visualization;


};

#endif
