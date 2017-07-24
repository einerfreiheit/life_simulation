#ifndef FACTORIES_WORKERFACTORY_H_
#define FACTORIES_WORKERFACTORY_H_

#include "../Workers/WorldWorker.h"
#include <vector>

class WorkerFactory {
public:
	WorkerFactory();
	~WorkerFactory();
	template<typename T> static void addWorker(std::vector<WorldWorker*> &workers, bool condition = true) {

		if (condition) {
			workers.push_back(new T);
		}

	}

	static void build(std::vector<WorldWorker*>&workers);

};

#endif
