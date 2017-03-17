#ifndef SIMULATIONDATA_H_
#define SIMULATIONDATA_H_
#include "World.h"


//@ этот класс плох тем, что соединяет в себе напрямую и мир, и поля конфигурации
//@ лучше все действия с конфигурацией вынести в отдельный класс, а после его тут прописать
class SimulationData {
public:
	static const SimulationData *getInst() {
		static SimulationData *inst=nullptr;//@ хорошо было бы проинициализировать этот указатель NULL
		if (!inst)
			inst = new SimulationData;
		return inst;
	}
//	World * world;

	int mapHeightToSet;
	int mapWidthToSet;
	int timeToWait;
	double gainResourcePerCell;
	bool useAIWorker ;
	bool useCreatureRemoveWorker;
	bool useCreatureSpawnWorker;
	bool useResourceWorker;
	bool useVideoWriterWorker;
	bool useVisualWorker ;
	bool useWaiterWorker;
	bool useCreatureActionWorker;
private:
	void readConfigParameters();
	SimulationData();
	SimulationData(const SimulationData& root);
	SimulationData& operator=(const SimulationData&);
};

#endif
