#ifndef CREATURESTATISTICS_H_
#define CREATURESTATISTICS_H_

#include "Genetics/Genome.h"

class CreatureStatistics {
public:
	CreatureStatistics();
	virtual ~CreatureStatistics();

	void incrementConjugationNumber();
	void incrementLifetime();
	void incrementAttacksNumber();
	void incrementFissionsNumber();
	void incrementEatenFood( double creatureBait);
	void incrementTraveledDistace();
	void updateGenomeComlexity(const GenomePtr genome);
	void setCreatureId(int id);

	void writeStatistics();

private:
	int id;
	int lifeTime;
	int attacksNumber;
	int fissionsNumber;
	float eatenFood;
	int traveledDistace;
	int genomeComlexity;
	int conjugationsNumber;

};

#endif


