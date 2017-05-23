#ifndef PHENOTYPE_H
#define PHENOTYPE_H
#include <string>

class Phenotype
{
public:
    Phenotype();
    ~Phenotype();
    double energyFromFood;
    double creatureOneBait;
    double energyToMove;
    double fissionLoss;
    double fissionThreshold;
    double hungryEdge;
    double corpseSize;
    double energyToClimb;
    double healthPoints;
    double attackPower;
    double creatureSize;
    int geneTranslationNumber=1;
    double maxHealthPoints=100.0;
    
    std::string cellReceptor;
    
    
    

};

#endif // PHENOTYPE_H
