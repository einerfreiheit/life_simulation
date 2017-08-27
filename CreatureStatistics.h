#ifndef CREATURESTATISTICS_H_
#define CREATURESTATISTICS_H_

#include "Genetics/Genome.h"

class CreatureStatistics {
public:
	CreatureStatistics();
	virtual ~CreatureStatistics();

	void updateConjugationNumber();
	void setCreatureId(const int id);//@ const не нужон
	void updateLifetime();
	void updateAttacksNumber();
	void updateFissionsNumber();
	void updateEatenFood(const double creatureBait); //@ и тут не нужен
	void updateDistanceMoved();
	void writeStatistics();//@ вынести дальше от методов модификации
	void updateGenomeComlexity(const GenomePtr genome); //@ а тут нужен, но можно по ссылке передать
private:
	int id;
	int lifeTime;
	int attacksNumber;
	int fissionNumber;//@ множ. число
	double eatenFood;
	int distanceMoved;//@ ?!@?!
	int genomeComlexity;
	int conjugationNumber; //@ множ. число

};

#endif


