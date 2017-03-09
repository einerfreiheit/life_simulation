#include "WorkerFactory.h"
#include "Workers/VisualWorker.h"

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


