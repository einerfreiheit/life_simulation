#ifndef FACTORIES_WORKERFACTORY_H_
#define FACTORIES_WORKERFACTORY_H_
#include "../Workers/WorldWorker.h"
#include <vector>
class WorkerFactory {
public:
	WorkerFactory();
	~WorkerFactory();
	std::vector<WorldWorker *> workers;
	void build( WorldWorker *worker);//@ переоборудуй таможню в фабрику, пусть метод build будет статичным и будет возвращать через ссылку вектор воркеров

};

#endif /* FACTORIES_WORKERFACTORY_H_ */
