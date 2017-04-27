#ifndef GENOMEBUILDER_H
#define GENOMEBUILDER_H
#include "../Genetics/Genome.h"
#include "../Creature.h"

class GenomeBuilder
{
public:
    static GenomePtr build ( int complexity = 20 );
    static GenomePtr build (CreaturePtr creature);
    

private:
    static const int complexityPerChromosome = 8;
};

#endif
