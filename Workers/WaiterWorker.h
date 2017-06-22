#ifndef WORKERS_WAITERWORKER_H_
#define WORKERS_WAITERWORKER_H_
#include "WorldWorker.h"

class WaiterWorker: public WorldWorker {
public:
	WaiterWorker();
	virtual ~WaiterWorker();
	void work(World *world) override;
private:
	int waitingTime;

};

#endif
