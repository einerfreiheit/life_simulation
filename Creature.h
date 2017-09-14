#ifndef CREATURE_H_
#define CREATURE_H_

#include "Actions/SimpleAction.h"
#include <vector>
#include <memory>
#include <iterator>
#include "Genetics/Genome.h"
#include "Phenotype.h"
#include "CreatureStatistics.h"

class Creature {
public:
	Creature(int id);
	virtual ~Creature();

	std::vector<SimpleAction*> actions;
	bool isHungry() const;
	CreatureStatistics *stats=NULL;
	void setGenome(GenomePtr genome);
	void setPhenotype(PhenotypePtr phenotype);
	int getId() const;
	GenomePtr getGenome() const;

	PhenotypePtr phenotype=NULL;
	GenomePtr genome=NULL;
	bool hasBeenAttacked = false;

	float energy;
	float lowEnergyLevel = 100.0;//@ почему инициализация некоторых штук идёт тут, а некоторых не тут?
	int x;
	int y;

protected:
	int id;


};
typedef std::shared_ptr<Creature> CreaturePtr;
#endif
