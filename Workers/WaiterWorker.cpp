#include "WaiterWorker.h"
#include <unistd.h>

WaiterWorker::WaiterWorker()
{
  this->name = "WaiterWorker";
  this->waitingTime = SimulationData::getInst()->timeToWait;

}

void WaiterWorker::work ( World *world )
{
  usleep ( waitingTime );
}
WaiterWorker::~WaiterWorker()
{
}

