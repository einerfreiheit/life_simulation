#include "GeneticsUtils.h"
#include "MutationUnit.h"
#include <stdlib.h>
#include <iostream>


MutationUnit::MutationUnit()
{
  
}

MutationUnit::~MutationUnit()
{

}

void MutationUnit::mutate ( GenomePtr genome )
{
   type = static_cast<MUTATION_TYPE> ( rand() % MT_END );
   switch (type){
     case MT_GENE_VALUE:{
      geneValueMutation(genome); 
       break;
     }
     case MT_GENE_TYPE:{
      geneTypeMutation(genome);
      break;
       
       
     }
     
     
     
   }
}

void MutationUnit::geneValueMutation(GenomePtr genome)
{
  Gene &geneToModify = getRandomGene(genome);
  geneToModify.allel1=GeneticsUtils::rangedRandom(-1,1);
  geneToModify.allel2=GeneticsUtils::rangedRandom(-1,1);
  
  std::cout<<"genes value has been modified to "<<geneToModify.allel1<<' '<<geneToModify.allel2<<std::endl;
  
  
}

void MutationUnit::geneTypeMutation ( GenomePtr genome )
{
   Gene &geneToModify = getRandomGene(genome);
   geneToModify.type = static_cast<GENE_TYPE> ( rand() % GT_ENUM_END );
   std::cout<<"gene type has been modified to "<< geneToModify.type<<std::endl;
}


Gene& MutationUnit::getRandomGene ( GenomePtr genome )
{
  int chromosomesNumber = genome->chromosomes.size();
  int randomChromosome = rand() % chromosomesNumber;
  int genesNumber = genome->chromosomes[randomChromosome]->genes.size();
  int randomGene=rand()%genesNumber;
  return  genome->chromosomes[randomChromosome]->genes[randomGene];
  
  
}
