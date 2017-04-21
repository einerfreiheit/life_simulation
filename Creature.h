#ifndef CREATURE_H_
#define CREATURE_H_
#include "Actions/SimpleAction.h"
#include <vector>
#include <memory>
#include "Genetics/Genome.h"
 struct Phenotype {
        double energyFromFood;
        double creatureOneBait;
        double energyToMove;
        double fissionLoss;
        double fissionThreshold;
	double hungryEdge;
    };

class Creature
{
public:
    Creature ( int id );
    virtual ~Creature();
    
    Phenotype* getPhenotype() const;
    
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
protected:
    int x;
    int y;
    int id;

    GenomePtr genome = NULL;
    
    Phenotype *phenotype= nullptr;
    void setPhenotype(Phenotype *phenotype);
};

#endif /* CREATURE_H_ */
