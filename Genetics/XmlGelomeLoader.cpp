#include "XmlGelomeLoader.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

XmlGelomeLoader::XmlGelomeLoader() {

}

XmlGelomeLoader::~XmlGelomeLoader() {
}

void XmlGelomeLoader::readXml(const char *fileName) {
	std::ofstream out("test.txt");
	TiXmlDocument document(fileName);
	if (!document.LoadFile()) {
		throw std::runtime_error("cannot load genome file!");

	}

	TiXmlElement *element;
	TiXmlHandle handle(&document);
	element = handle.FirstChild("Genome").FirstChild("Chromosomes").FirstChild("Chromosome").ToElement();
	if (element) {
		readGenomeSection(element, out);

	}
	element = handle.FirstChild("Genome").Child(1).FirstChild("Chromosome").ToElement();
	if (element) {
		readGenomeSection(element, out);

	}
}

void XmlGelomeLoader::readGenomeSection(TiXmlElement *section, std::ofstream & out) {
	if (!section) {
		return;
	}
	int i=0;
	for (section; section; section = section->NextSiblingElement()) {
		TiXmlElement *gene = section->FirstChild("Gene")->ToElement();
		while (gene) {
			out << gene->Attribute("type") << " " << gene->Attribute("allel1") << " " << gene->Attribute("allel2")
					<<"number "<<i<< std::endl;
			gene = gene->NextSiblingElement("Gene");
		}
		i++;

	}

}
