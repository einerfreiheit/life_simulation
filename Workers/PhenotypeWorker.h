
#ifndef PHENOTYPEWORKER_H
#define PHENOTYPEWORKER_H
#include "WorldWorker.h"
#include"../Genetics/Gene.h"
class PhenotypeWorker: public WorldWorker
{
public:
    PhenotypeWorker();
    ~PhenotypeWorker();
    void work ( World *world ) override;

private:
    void updatePhenotype ( CreaturePtr creature );
    void grow ( CreaturePtr creature, Gene& gene );
    void changeTranslationSpeed ( CreaturePtr creature, Gene& gene );
    void regenerate ( CreaturePtr creature, Gene& gene );
    bool canTranslate(CreaturePtr creature, Gene& gene);
};

#endif // PHENOTYPEWORKER_H
