#ifndef CREATURE_H_
#define CREATURE_H_

#include "Actions/SimpleAction.h"
#include <vector>
#include <memory>
#include <iterator>
#include "Genetics/Genome.h"
#include "Phenotype.h"

class Creature
{
public:
    Creature ( int id );
    virtual ~Creature();
    std::vector<SimpleAction*> creatureActions;
    bool isHungry() const;
    double energy;
    double lowEnergyLevel = 100.0;
    int getPosY() const;//@ перемешаны методы и поля
    int getPosX() const;
    void setPosY ( int setY );//@ геттеры и сеттеры есть => зачем они нужны?
    void setPosX ( int setX );
    void setEnergy ( double energyToSet );
    double getEnergy() const;
    int getId() const;
    void setGenome ( GenomePtr genome );
    GenomePtr getGenome();
    void setPhenotype ( PhenotypePtr phenotype );
    PhenotypePtr phenotype;
    bool hasBeenAttaked=false;
  
protected:
    int x;
    int y;
    int id;

    GenomePtr genome;

};
typedef  std::shared_ptr<Creature> CreaturePtr;//@ std::shared_ptr = рак
#endif /* CREATURE_H_ */
