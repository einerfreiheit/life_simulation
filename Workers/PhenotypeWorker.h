

#ifndef PHENOTYPEWORKER_H
#define PHENOTYPEWORKER_H
#include "WorldWorker.h"
class PhenotypeWorker: public WorldWorker
{
public:
    PhenotypeWorker();
    ~PhenotypeWorker();
    void work(World *world) override;
private: void changePhenotype( CreaturePtr creature);
};

#endif // PHENOTYPEWORKER_H
