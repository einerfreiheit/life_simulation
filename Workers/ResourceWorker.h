#ifndef WORKERS_RESOURCEWORKER_H_
#define WORKERS_RESOURCEWORKER_H_
#include "WorldWorker.h"

class ResourceWorker: public WorldWorker {
public:
	ResourceWorker();
	virtual ~ResourceWorker();
    void work(World *world) override;
private:
    double gainPerCell;
	void setRandomXY(World* world);
    int rand_y;
    int rand_x;

};

#endif
