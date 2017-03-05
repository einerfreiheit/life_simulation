#ifndef WORKERS_CREATUREREMOVEWORKER_H_
#define WORKERS_CREATUREREMOVEWORKER_H_
#include "WorldWorker.h"


class CreatureRemoveWorker : public WorldWorker{
public:
	CreatureRemoveWorker();
	void work(World *world) override;
	virtual ~CreatureRemoveWorker();
};

#endif
