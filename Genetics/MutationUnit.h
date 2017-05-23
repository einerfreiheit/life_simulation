
#ifndef MUTATIONUNIT_H
#define MUTATIONUNIT_H
#include "Genome.h"
enum MUTATION_TYPE{
 MT_GENE_VALUE=0,
 MT_GENE_TYPE=1,
 MT_END=2
};
class MutationUnit
{
public:
    MutationUnit();
    ~MutationUnit();
    MUTATION_TYPE type;
    void mutate(GenomePtr genome);
private: 
  void geneValueMutation(GenomePtr genome);
  void geneTypeMutation(GenomePtr genome);
  Gene& getRandomGene(GenomePtr genome);
  
};

#endif // MUTATIONUNIT_H
