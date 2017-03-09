#include "WorkerFactory.h"
#include "../Workers/VisualWorker.h"
#include <vector>
void WorkerFactory::build(){
	WorldWorker *worker;
	worker =new VisualWorker;
	if (worker->isAvailable==true){
		this->workers.push_back(worker);

	}

}
WorkerFactory::WorkerFactory(){
	this->workers;
}


