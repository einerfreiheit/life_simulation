#ifndef FACTORIES_WORKERFACTORY_H_
#define FACTORIES_WORKERFACTORY_H_
#include "../Workers/WorldWorker.h"
#include <vector>
class WorkerFactory {
public:
	WorkerFactory();
	~WorkerFactory();
	std::vector <WorldWorker *> workers;
	void build(WorldWorker *worker);
//	std::vector <WorldWorker *> workers;
	int q;

};

#endif /* FACTORIES_WORKERFACTORY_H_ */
