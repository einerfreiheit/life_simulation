#ifndef WORKERS_RESOURCEWORKER_H_
#define WORKERS_RESOURCEWORKER_H_
#include "WorldWorker.h"

class ResourceWorker: public WorldWorker {
public:
	ResourceWorker();
	virtual ~ResourceWorker();
    void work(World *world) override;
    static inline void getRandom(int&value,int border);
private:
    double gainPerCell;

};

#endif
