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

	std::vector<SimpleAction*> creatureActions;
	bool isHungry() const;
	CreatureStatistics *stats;
	void setGenome(GenomePtr genome);
	void setPhenotype(PhenotypePtr phenotype);
	int getId() const;
	GenomePtr getGenome() const;


	PhenotypePtr phenotype;
	GenomePtr genome;
	bool hasBeenAttaked = false;

	double energy;
	double lowEnergyLevel = 100.0;
	int x;
	int y;

protected:
	int id;


};
typedef std::shared_ptr<Creature> CreaturePtr;
#endif
