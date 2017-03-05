#ifndef WORKERS_RESOURCEWORKER_H_
#define WORKERS_RESOURCEWORKER_H_
#include "WorldWorker.h"

class ResourceWorker: public WorldWorker {
public:
	ResourceWorker();
	virtual ~ResourceWorker();
    void work(World *world) override;
    double gainPerCell;
    void setAverageGainPerCell(double gainPerCellToSet);

	void setRandomXY(World* world);
	private:
    int rand_y;
    int rand_x;

};

#endif
