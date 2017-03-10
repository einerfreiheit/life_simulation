#ifndef FACTORIES_WORKERFACTORY_H_
#define FACTORIES_WORKERFACTORY_H_
#include "../Workers/WorldWorker.h"
#include <vector>
class WorkerFactory {
public:
	WorkerFactory();
	~WorkerFactory();
	std::vector<WorldWorker *> workers;
	void build(WorldWorker *worker);

};

#endif /* FACTORIES_WORKERFACTORY_H_ */
