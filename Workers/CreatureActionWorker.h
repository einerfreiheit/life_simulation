#ifndef WORKERS_CREATUREACTIONWORKER_H_
#define WORKERS_CREATUREACTIONWORKER_H_

#include "WorldWorker.h"

class CreatureActionWorker: public WorldWorker {
public:
	CreatureActionWorker();
	virtual ~CreatureActionWorker();
    void work ( World *world ) override;

};

#endif
