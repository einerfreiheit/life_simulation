#ifndef AIWORKER_H
#define AIWORKER_H
#include "../Actions/Action.h"
#include "WorldWorker.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"

class AIWorker: public WorldWorker {
public:
	AIWorker();
	~AIWorker();
	Eat eat;
	Move move;
	void work(World *world) override;
};

#endif // AIWORKER_H
