
#ifndef METABOLISMWORKER_H
#define METABOLISMWORKER_H
#include "WorldWorker.h"
#include"../Genetics/Gene.h"
class MetabolismWorker: public WorldWorker
{
public:
    MetabolismWorker();
    ~MetabolismWorker();
    void work ( World *world ) override;

private:
    void updatePhenotype ( CreaturePtr creature );
    void grow ( CreaturePtr creature, Gene& gene );
    void regenerate ( CreaturePtr creature, Gene& gene );
    bool canTranslate(CreaturePtr creature, Gene& gene);
    void readAgressionLevel(CreaturePtr creature, Gene& gene);
};

#endif 
