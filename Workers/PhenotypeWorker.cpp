#include "PhenotypeWorker.h"
#include "../Phenotype.h"
#include "../Genetics/Genome.h"
#include <iostream>
PhenotypeWorker::PhenotypeWorker()
{

}
void PhenotypeWorker::work ( World* world )
{
  for ( CreaturePtr creature: world->creatures )
    {

      changePhenotype ( creature );
    }
}

PhenotypeWorker::~PhenotypeWorker()
{

}

void PhenotypeWorker::changePhenotype ( CreaturePtr creature )
{
  GenomePtr genome=creature->getGenome();
  size_t chromosomesNumber=genome->chromosomes.size();
  for ( size_t i=0; i<chromosomesNumber; i++ )
    {
      size_t genesNumber= genome->chromosomes[i]->genes.size();
      for (size_t j=0; j<genesNumber;j++){
	  std::cout<<genome->chromosomes[i]->genes[j].allel1;
      }

    }

}


