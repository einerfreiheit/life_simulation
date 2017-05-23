
#ifndef GENOMEWORKER_H
#define GENOMEWORKER_H
#include "WorldWorker.h"
#include "../Genetics/MutationUnit.h"
class GenomeWorker  : public WorldWorker
{
public:
    GenomeWorker();
    ~GenomeWorker();
    void work(World *world) override;
private:
    int mutationRate = 1;
    MutationUnit* unit = NULL;
    void updateCellReceptor(CreaturePtr creature);
    
    
    
};

#endif // GENOMEWORKER_H
