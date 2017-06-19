#ifndef METABOLISMWORKER_H
#define METABOLISMWORKER_H

#include "WorldWorker.h"
#include"../Genetics/Gene.h"

class MetabolismWorker: public WorldWorker {
public:
	MetabolismWorker();
	~MetabolismWorker();
	void work(World *world) override;

private:
	static void updatePhenotype(CreaturePtr creature);
	static void grow(CreaturePtr creature, const Gene& gene);
	static void regenerate(CreaturePtr creature, const Gene& gene);
	static bool canTranslate(CreaturePtr creature, const Gene& gene);
	static void readAgressionLevel(CreaturePtr creature, const Gene& gene);
};

#endif 
