#ifndef WORKERS_RESOURCEWORKER_H_
#define WORKERS_RESOURCEWORKER_H_

#include "WorldWorker.h"

class ResourceWorker: public WorldWorker {
public:
	ResourceWorker();
	virtual ~ResourceWorker();
	void work(World *world) override;
	static inline Cell* getRandom(World *world);
private:
	double gainPerCell;
	int cellNumber;
	Cell *randomCell = NULL;

};

#endif
