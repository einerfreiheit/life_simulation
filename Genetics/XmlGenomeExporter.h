#ifndef GENETICS_XMLGENOMEEXPORTER_H_
#define GENETICS_XMLGENOMEEXPORTER_H_

#include "XmlSimpleEporter.h"
#include "../Creature.h"


class XmlGenomeExporter {
public:
	static void buildXml(CreaturePtr creature);
private:
	static void addGene(const Gene& gene);
	static void addGenes(const ChromosomePtr chromosome, TiXmlElement *elementChromosome);
	static void addGenome(	TiXmlElement *rootElement,
									const std::vector<ChromosomePtr>& chromosomes);

};

#endif
