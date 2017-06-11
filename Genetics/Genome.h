#ifndef GENOME_H
#define GENOME_H

#include "Chromosome.h"

class Genome
{
public:
    Genome();
    ~Genome();
    
    std::vector<ChromosomePtr> chromosomes;
    std::vector<ChromosomePtr> plasmide;
};

typedef std::shared_ptr<Genome> GenomePtr;

#endif // GENOME_H
