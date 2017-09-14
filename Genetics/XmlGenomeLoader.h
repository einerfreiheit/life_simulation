#ifndef GENETICS_XMLGENOMELOADER_H_
#define GENETICS_XMLGENOMELOADER_H_

#include <vector>
#include <tinyxml.h>
#include "../Creature.h"
#include <string>


#include "../Factories/GenomeBuilder.h"
#include "Genome.h"

class XmlGenomeLoader {
public:

	static GenomePtr buildGenome(std::string fileName);
	static void buildChromosomes(TiXmlElement *section, GenomePtr genome );
};

#endif
