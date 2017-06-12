#ifndef PHENOTYPEBUILDER_H
#define PHENOTYPEBUILDER_H

#include "Phenotype.h"
#include "../Genetics/Genome.h"

class PhenotypeBuilder

{
public:
	static PhenotypePtr build(GenomePtr genome);
};

#endif
