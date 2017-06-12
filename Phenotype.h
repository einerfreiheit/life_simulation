#ifndef PHENOTYPE_H
#define PHENOTYPE_H

#include <string>
#include <memory>

class Phenotype {
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
	double conjugateEnergy = 50.0;

	bool isAggresive = false;

	double geneTranslationSpeed = 1.0;
	int maxGeneTranslationNumber = 5;
	int geneTranslationNumber = 1;

	double maxHealthPoints = 100.0;

	std::string cellReceptor;
};
typedef std::shared_ptr<Phenotype> PhenotypePtr;

#endif // PHENOTYPE_H
