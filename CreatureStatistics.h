#ifndef CREATURESTATISTICS_H_
#define CREATURESTATISTICS_H_
#include "Genetics/Genome.h"
class CreatureStatistics {
public:
	CreatureStatistics();
	virtual ~CreatureStatistics();

	void updateConjugationNumber();
	void setCreatureId(const int id);
	void updateLifetime();
	void updateAttacksNumber();
	void updateFissionsNumber();
	void updateEatenFood(const double creatureBait);
	void updateDistanceMoved();
	void writeStatistics();
	void updateGenomeComlexity(const GenomePtr genome);
private:
	int id;
	int lifeTime;
	int attacksNumber;
	int fissionNumber;
	double eatenFood;
	int distanceMoved;
	int genomeComlexity;
	int conjugationNumber;

};

#endif


