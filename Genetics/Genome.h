#ifndef GENOME_H
#define GENOME_H

#include "Chromosome.h"

class Genome
{
public:
    Genome();
    ~Genome();
    
    std::vector<Chromosome> chromosomes;
};

#endif // GENOME_H
