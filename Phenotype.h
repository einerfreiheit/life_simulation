#ifndef PHENOTYPE_H
#define PHENOTYPE_H

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
};

#endif // PHENOTYPE_H
