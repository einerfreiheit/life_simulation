#ifndef GENETICS_XMLGENOMEEXPORTER_H_
#define GENETICS_XMLGENOMEEXPORTER_H_

#include <vector>
#include <tinyxml.h>
#include "../Creature.h"
#include <string>

class XmlGenomeExporter {
public:
	static void buildXml(CreaturePtr creature);
private:
	static void addGene(const Gene& gene);
	static void addChromosome(const ChromosomePtr chromosome, TiXmlElement *elementChromosome);
	static void addGenomeSection(	TiXmlElement *rootElement,
									const std::vector<ChromosomePtr>& chromosomes,
									std::string &sectionName);

};

#endif
