#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_
#include "WorldWorker.h"


class VisualWorker : public WorldWorker {
public:
	VisualWorker();
	virtual ~VisualWorker();
	void work (World *world) override;
	void getImage(World *world);
	void showImage(World *world);
};

#endif /* WORKERS_VISUALWORKER_H_ */
