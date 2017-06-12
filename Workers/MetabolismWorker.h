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
	static void grow(CreaturePtr creature, Gene& gene); //const Gene& везде, где ген не меняется
	static void regenerate(CreaturePtr creature, Gene& gene);
	static bool canTranslate(CreaturePtr creature, Gene& gene);
	static void readAgressionLevel(CreaturePtr creature, Gene& gene);
};

#endif 
