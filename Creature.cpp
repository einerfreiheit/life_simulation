#include "Creature.h"
#include "SimulationData.h"
Creature::Creature ( int _id ) : id ( _id ) {

    energy = 0.0;
    x = 0;
    y = 0;
    phenotype=new Phenotype;
    setPhenotype(phenotype);
    }

void Creature::setPhenotype ( Phenotype* phenotype ) {
  // пока фенотип = конфигу
    phenotype->creatureOneBait=SimulationData::getInst()->creatureOneBait;
    phenotype->energyFromFood=SimulationData::getInst()->energyFromFood;
    phenotype->energyToMove=SimulationData::getInst()->energyToMove;
    phenotype->fissionLoss=SimulationData::getInst()->fissionLoss;
    phenotype->fissionThreshold=SimulationData::getInst()->fissionThreshold;
    phenotype->hungryEdge=100;
    phenotype->corpseSize=50;

    }
    
Phenotype* Creature::getPhenotype() const {
     return phenotype;
    }


void Creature::setPosX ( int setX ) {

    this->x = setX;
    }
void Creature::setPosY ( int setY ) {
    this->y = setY;

    }
int Creature::getPosX() const {

    return this->x;
    }
int Creature::getPosY() const {
    return this->y;

    }

int Creature::getId() const {
    return id;
    }

bool Creature::isHungry() const {

    return this->energy <= getPhenotype()->hungryEdge;
    }

double Creature::getEnergy() const {
    return this->energy;

    }
void Creature::setEnergy ( double energyToSet ) {
    this->energy = energyToSet;

    }


void Creature::setGenome ( GenomePtr _genome ) {
    this->genome = _genome;
    }

Creature::~Creature() {
    if ( genome ) {
        delete genome;
        }
        delete phenotype;
    }

