#ifndef GENOME_H
#define GENOME_H

#include "Chromosome.h"

class Genome
{
public:
    Genome();
    ~Genome();
    
    std::vector<ChromosomePtr> chromosomes;
};

typedef Genome * GenomePtr;

#endif // GENOME_H
