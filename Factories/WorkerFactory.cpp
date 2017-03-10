#include "WorkerFactory.h"
#include <vector>
void WorkerFactory::build(WorldWorker *worker) {
	if (worker->isAvailable == true) {
		this->workers.push_back(worker);

	}
}
WorkerFactory::WorkerFactory() {
	this->workers.reserve(10);
}

WorkerFactory::~WorkerFactory() {
}
