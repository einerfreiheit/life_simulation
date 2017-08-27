#include <stdexcept>
#include "XmlGenomeLoader.h"

GenomePtr XmlGenomeLoader::buildGenome(const char *fileName) {

	TiXmlDocument document(fileName);
	if (!document.LoadFile()) {
		throw std::runtime_error("cannot load genome file!"); //@ что за файл? вдруг там 47 хромосома

	}
	GenomePtr genome = std::shared_ptr<Genome>(new Genome);

	TiXmlElement *element;
	TiXmlHandle handle(&document);
	element = handle.FirstChild("Chromosomes").FirstChild("Chromosome").ToElement();
	if (element) {
		buildChromosomes(element, genome);

	}

	return genome;
}

void XmlGenomeLoader::buildChromosomes(TiXmlElement *chromosomeElement, GenomePtr genome) {
	if (!chromosomeElement) {//@ ни нужно
		return;
	}
	int type;
	float allel1;
	float allel2;
	for (chromosomeElement; chromosomeElement; chromosomeElement = chromosomeElement->NextSiblingElement()) {
		TiXmlElement *geneElement = chromosomeElement->FirstChild("Gene")->ToElement();
		ChromosomePtr chromosome = std::shared_ptr<Chromosome>(new Chromosome);
		while (geneElement) {

			geneElement->QueryIntAttribute("type", &type);
			geneElement->QueryFloatAttribute("allel1", &allel1);
			geneElement->QueryFloatAttribute("allel2", &allel2);
			chromosome->genes.push_back(Gene(static_cast<GENE_TYPE>(type), allel1, allel2));
			geneElement = geneElement->NextSiblingElement("Gene");

		}
		genome->chromosomes.push_back(chromosome);

	}

}
