
#include "Phenotype.h"
#include "SimulationData.h"
Phenotype::Phenotype()
{
  creatureOneBait=SimulationData::getInst()->creatureOneBait;
  energyFromFood=SimulationData::getInst()->energyFromFood;
  energyToMove=SimulationData::getInst()->energyToMove;
  fissionLoss=SimulationData::getInst()->fissionLoss;
  fissionThreshold=SimulationData::getInst()->fissionThreshold;
  hungryEdge=100;
  healthPoints=SimulationData::getInst()->creatureHealthPoints;
  attackPower=SimulationData::getInst()->creatureAttackPower;
  creatureSize=10.0;

}

Phenotype::~Phenotype()
{

}
