#ifndef FACTORIES_WORKERFACTORY_H_
#define FACTORIES_WORKERFACTORY_H_
#include "Workers/WorldWorker.h"
#include <vector>
class WorkerFactory {
public:
	WorkerFactory();
	~WorkerFactory();
	void build();
	std::vector <WorldWorker *> workers;

};

#endif /* FACTORIES_WORKERFACTORY_H_ */
