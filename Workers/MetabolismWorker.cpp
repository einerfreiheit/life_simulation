#include "MetabolismWorker.h"
#include "../Phenotype.h"
#include "../Genetics/Genome.h"
#include "../Genetics/Gene.h"
#include <iostream>
MetabolismWorker::MetabolismWorker()
{
  this->name="MetabolismWorker";
}
void MetabolismWorker::work ( World* world )
{
  for ( CreaturePtr creature: world->creatures )
    {
      std::cout<<creature->getId() <<"id"<<std::endl;
      updatePhenotype ( creature );
    }
}

MetabolismWorker::~MetabolismWorker()
{

}

bool MetabolismWorker::canTranslate ( CreaturePtr creature, Gene& gene )
{
  return (gene.allel1>0.0 && creature->getEnergy()>=gene.allel1);
}

void MetabolismWorker::regenerate ( CreaturePtr creature, Gene& gene )
{
  if ( canTranslate(creature,gene) && creature->phenotype->maxHealthPoints > creature->phenotype->healthPoints )
    {
      creature->phenotype->healthPoints+=gene.allel1;
      creature->setEnergy ( creature->getEnergy()-gene.allel1 );
      std::cout<< "creature id"<<creature->getId() <<" regenerates to "<<creature->phenotype->healthPoints<<std::endl;
    }
}


void MetabolismWorker::grow ( CreaturePtr creature, Gene &gene )
{
  if (canTranslate(creature,gene))
    {
      creature->phenotype->creatureSize+=gene.allel1;
      creature->setEnergy ( creature->getEnergy()-gene.allel1 );
      std::cout<<"creature id"<<creature->getId() <<" grows to size "<<creature->phenotype->creatureSize<<std::endl;
    }
}






void MetabolismWorker::updatePhenotype ( CreaturePtr creature )
{
  int chromosomeIndex=0;
  for ( ChromosomePtr chromosome : creature->getGenome()->chromosomes )

    {
      for ( int i=0; i<creature->phenotype->geneTranslationNumber; i++ )
        {

         
          if ( chromosome->position>=chromosome->genes.size() )
            {
              chromosome->position=0;
            }

          Gene &currentGene =chromosome->genes[chromosome->position];
          std::cout<<"chromosome "<< chromosomeIndex<<" "<<"gene "<<chromosome->position<<" type "<<currentGene.type <<"chromosome size: "<<chromosome->genes.size() <<std::endl;

          switch ( currentGene.type )
            {
            case GT_GROW:
            {
              grow ( creature,currentGene );
              break;

            }
            case GT_REGENERATION:
            {
              regenerate ( creature,currentGene );
              break;

            }
           
            
	   
	}


          chromosome->position++;


        }
      chromosomeIndex++;

    }


}







