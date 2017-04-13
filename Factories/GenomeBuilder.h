#ifndef GENOMEBUILDER_H
#define GENOMEBUILDER_H

#include "../Genetics/Genome.h"

class GenomeBuilder
{
public:
    static GenomePtr build(int complexity = 20);
private:
    static const int complexityPerChromosome = 8;
};

#endif
