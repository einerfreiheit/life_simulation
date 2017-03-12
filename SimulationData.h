#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_
#include "World.h"


//@ этот класс плох тем, что соединяет в себе напрямую и мир, и поля конфигурации
//@ лучше все действия с конфигурацией вынести в отдельный класс, а после его тут прописать
class SimulationData {
public:
	static const SimulationData *getInst() {
		static SimulationData *inst;//@ хорошо было бы проинициализировать этот указатель NULL
		if (!inst)
			inst = new SimulationData;
		return inst;
	}
	World * world;

	int mapHeightToSet;
	int mapWidthToSet;
	int timeToWait;
	double gainResourcePerCell;
	bool AIWorkerIsAvailable ;
	bool CreatureRemoveWorkerIsAvailable;
	bool CreatureSpawnWorkerIsAvailable;
	bool ResourceWorkerIsAvailable;
	bool VideoWriterWorkerIsAvailable;
	bool VisualWorkerIsAvailable ;//@ плохие названия: долгие, вводят в заблуждение
	bool WaiterWorkerIsAvailable;//@ IsAvailable может подразумевать, что объект может стать доступен, в то время как поля решают, будет ли вообще построен объект
//@ лучше было бы makeWaiterWorker, useWaiterWorker, buildWaiterWorker etc
private:
	void readConfigParameters();
	SimulationData();
	SimulationData(const SimulationData& root);
	SimulationData& operator=(const SimulationData&);
};

#endif
