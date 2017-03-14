#include "WaiterWorker.h"
#include <unistd.h>

WaiterWorker::WaiterWorker() {
	this->name = "WaiterWorker";
	this->waitingTime = SimulationData::getInst()->timeToWait;//@ вот тут всё здорово в этой строчке, для этого конфиг-синглтон и нужен

}

void WaiterWorker::work(World *world) {
	usleep(waitingTime);
}
WaiterWorker::~WaiterWorker() {
}

