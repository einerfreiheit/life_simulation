#include "XmlGenomeExporter.h"

void XmlGenomeExporter::buildXml(CreaturePtr creature) {

	TiXmlDocument *document = new TiXmlDocument("document");
	TiXmlDeclaration *declaration = new TiXmlDeclaration("1.0", "", "");
	document->LinkEndChild(declaration);
	TiXmlElement * rootElement = new TiXmlElement("Genome");
	document->LinkEndChild(rootElement);
	std::string name;
	name = "Chromosomes";
	addGenomeSection(rootElement, creature->getGenome()->chromosomes, name);
	name = "Plasmid";
	addGenomeSection(rootElement, creature->getGenome()->plasmid, name);

	document->SaveFile("genome_id_" + std::to_string(creature->getId()) + ".xml");

}

void XmlGenomeExporter::addGenomeSection(	TiXmlElement *rootElement,
											const std::vector<ChromosomePtr>& chromosomes,
											std::string &sectionName) {
	TiXmlElement *section = new TiXmlElement(sectionName);
	rootElement->LinkEndChild(section);

	for (auto chromosome : chromosomes) {
		TiXmlElement *element = new TiXmlElement("Chromosome");
		section->LinkEndChild(element);
		addChromosome(chromosome, element);

	}

}

void XmlGenomeExporter::addChromosome(const ChromosomePtr chromosome, TiXmlElement *elementChromosome) {
	for (auto gene : chromosome->genes) {

		TiXmlElement *elementGene = new TiXmlElement("Gene");
		elementGene->SetAttribute("type", gene.type);
		elementGene->SetDoubleAttribute("allel1", gene.allel1);
		elementGene->SetDoubleAttribute("allel2", gene.allel2);
		elementChromosome->LinkEndChild(elementGene);

	}

}
