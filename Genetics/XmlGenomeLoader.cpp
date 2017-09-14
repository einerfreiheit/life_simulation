#include <stdexcept>
#include "XmlGenomeLoader.h"
#include <string>

GenomePtr XmlGenomeLoader::buildGenome(std::string fileName) {

	TiXmlDocument document(fileName.c_str());
	if (!document.LoadFile()) {
		throw
	std::runtime_error("cannot load genome file" + fileName);

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
int type;
float allel1;
float allel2;
for (;; chromosomeElement = chromosomeElement->NextSiblingElement()) {
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
