#include "GenomeWorker.h"
#include "../Genetics/GeneticsUtils.h"
#include "../Genetics/MutationUnit.h"
#include "string"
#include <iostream>
GenomeWorker::GenomeWorker()
{
  unit= new MutationUnit;

}

GenomeWorker::~GenomeWorker()
{

}

void GenomeWorker::work ( World* world )
{

  for ( int mutationNumber=0; mutationNumber<mutationRate; mutationNumber++ )
    {
      int creaturesNumber = world->creatures.size();
      int randomCreaturePos = rand() % creaturesNumber;
      unit->mutate ( world->creatures[randomCreaturePos]->getGenome() );
      CreaturePtr randomCreature = world->creatures[randomCreaturePos];
      updateCellReceptor(randomCreature);
      
      

    }
}

void GenomeWorker::updateCellReceptor(CreaturePtr creature)
{
  creature->phenotype->cellReceptor.clear();
  for (ChromosomePtr chromosome: creature->getGenome()->chromosomes){
   for (Gene &gene :chromosome->genes){
     creature->phenotype->cellReceptor+=std::to_string(gene.type);
     
   }
    
  }
  std::cout<<creature->phenotype->cellReceptor<< std::endl;
}

