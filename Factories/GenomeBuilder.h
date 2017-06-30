#ifndef GENOMEBUILDER_H
#define GENOMEBUILDER_H

#include "../Genetics/Genome.h"
#include "../Creature.h"

class GenomeBuilder {
public:
	static GenomePtr build(int complexity = 20);
	static GenomePtr build(CreaturePtr creature);
	static void buildPlasmid(const GenomePtr genome);
	static Gene& getRandomGene(const GenomePtr genome);
	static void insertPlasmidToGenome(GenomePtr genome);
	static void replaceGene(GenomePtr recipient, Gene& plasmidGene);

private:

	static void crossingOver(GenomePtr genome);

	static const int complexityPerChromosome = 8;
};

#endif
