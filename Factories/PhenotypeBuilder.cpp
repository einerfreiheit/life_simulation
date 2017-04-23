#include "PhenotypeBuilder.h"
#include "../SimulationData.h"
Phenotype* PhenotypeBuilder::build ( GenomePtr genome ) {
    Phenotype *result;
    result = new Phenotype;
    result->corpseSize=50;
    result->creatureOneBait=SimulationData::getInst()->creatureOneBait;
    result->energyFromFood=SimulationData::getInst()->energyFromFood;
    result->energyToMove=SimulationData::getInst()->energyToMove;
    result->fissionLoss=SimulationData::getInst()->fissionLoss;
    result->fissionThreshold=SimulationData::getInst()->fissionThreshold;
    result->hungryEdge=100;
    return result;
  
  
 
    }

