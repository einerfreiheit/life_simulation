#ifndef PHENOTYPE_H
#define PHENOTYPE_H

#include <string>
#include <memory>

class Phenotype {
public:
	Phenotype();
	~Phenotype();
	float energyFromFood;
	float creatureOneBait;
	float energyToMove;
	float fissionLoss;
	float fissionThreshold;
	float hungryThershold;
	float energyToClimb;
	float healthPoints;
	float attackPower;
	float creatureSize;

	float conjugateEnergy = 5.0;
	float aggresion = 0.0;
	float geneTranslationSpeed = 1.0;
	int maxGeneTranslationNumber = 5;
	int geneTranslationNumber = 1;
	double maxHealthPoints = 100.0;

	std::string cellReceptor;
};
typedef std::shared_ptr<Phenotype> PhenotypePtr;

#endif
