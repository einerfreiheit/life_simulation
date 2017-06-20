#ifndef PHENOTYPEBUILDER_H
#define PHENOTYPEBUILDER_H

#include "Phenotype.h"
#include "../Genetics/Genome.h"

class PhenotypeBuilder

{
public:
	static PhenotypePtr build( const GenomePtr genome);
	static void processGene(const Gene&, PhenotypePtr phenotype);
	static void buildCreatureReceptor(const GenomePtr genome, PhenotypePtr phenotype);
};

#endif
