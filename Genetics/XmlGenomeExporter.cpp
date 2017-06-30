#include "XmlGenomeExporter.h"
#include <iostream>
void XmlGenomeExporter::buildXml(CreaturePtr creature) {

	TiXmlDocument *document = new TiXmlDocument("document");
	TiXmlDeclaration *declaration = new TiXmlDeclaration("1.0", "", "");
	document->LinkEndChild(declaration);

	TiXmlElement * rootElement = new TiXmlElement("Chromosomes");
	document->LinkEndChild(rootElement);

	addGenome(rootElement, creature->getGenome()->chromosomes);

	document->SaveFile("genome_id_" + std::to_string(creature->getId()) + ".xml");

}

void XmlGenomeExporter::addGenome(	TiXmlElement *rootElement,
									const std::vector<ChromosomePtr>& chromosomes) {
	for (auto chromosome : chromosomes) {
		TiXmlElement *chromosomeElement = XmlSimpleEporter::addElement(rootElement, "Chromosome");
		addGenes(chromosome, chromosomeElement);
	}

}

void XmlGenomeExporter::addGenes(const ChromosomePtr chromosome, TiXmlElement *elementChromosome) {
	for (auto gene : chromosome->genes) {
		TiXmlElement *elementGene = XmlSimpleEporter::addElement(elementChromosome, "Gene");
		XmlSimpleEporter::addAttribure(elementGene, "type", gene.type);
		XmlSimpleEporter::addDoubleAttribute(elementGene, "allel1", gene.allel1);
		XmlSimpleEporter::addDoubleAttribute(elementGene, "allel2", gene.allel2);

	}

}
