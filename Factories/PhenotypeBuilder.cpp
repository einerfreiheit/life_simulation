#include "PhenotypeBuilder.h"
#include "../SimulationData.h"
Phenotype* PhenotypeBuilder::build ( GenomePtr genome )
{
  Phenotype *result;
  result = new Phenotype;
  result->corpseSize=50;
  result->creatureOneBait=SimulationData::getInst()->creatureOneBait;
  result->energyFromFood=SimulationData::getInst()->energyFromFood;
  result->energyToMove=SimulationData::getInst()->energyToMove;
  result->fissionLoss=SimulationData::getInst()->fissionLoss;
  result->fissionThreshold=SimulationData::getInst()->fissionThreshold;
  result->hungryEdge=100;
  result->energyToClimb=result->energyToMove*2;

  for ( ChromosomePtr chromosome : genome->chromosomes )
    {
      for ( Gene &gene : chromosome->genes )
        {

          switch ( gene.type )
            {
            case GT_AGRESSION:
            {
              if ( gene.allel1>0.0 && result->isAggresive==false )
                {
                  result->isAggresive=true;
                  break;
                }
            }
            case GT_TRANSLATION:
            {
              if ( gene.allel1>0.0 )
                {
                  result->geneTranslationSpeed+=gene.allel1;
                  break;
                }


            }
            }




        }
    }

  int geneNumberToTranslate = ( int ) result->geneTranslationSpeed;
  if ( geneNumberToTranslate> result->maxGeneTranslationNumber )
    {
      result->geneTranslationNumber=result->maxGeneTranslationNumber;
    }
  else
    {
      result->geneTranslationNumber=geneNumberToTranslate;
    }


  return result;






}

