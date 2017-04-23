#ifndef CREATURE_H_
#define CREATURE_H_
#include "Actions/SimpleAction.h"
#include <vector>
#include <memory>
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
    int getPosY() const;
    int getPosX() const;
    void setPosY ( int setY );
    void setPosX ( int setX );
    void setEnergy ( double energyToSet );
    double getEnergy() const;
    int getId() const;
    void setGenome ( GenomePtr genome );
    void setPhenotype (Phenotype *phenotype);
    Phenotype *phenotype;

protected:
    int x;
    int y;
    int id;

    GenomePtr genome = NULL;
    
};

#endif /* CREATURE_H_ */
