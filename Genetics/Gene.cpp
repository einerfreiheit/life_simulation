#include "Gene.h"
#include "GeneticsUtils.h"
#include <stdlib.h>

Gene::Gene() {
	type = static_cast<GENE_TYPE>(rand() % GT_ENUM_END);
	allel1 = GeneticsUtils::rangedRandom(-1, 1);
	allel2 = GeneticsUtils::rangedRandom(-1, 1);
}

Gene::Gene(GENE_TYPE type, float allel1, float allel2) :
		type(type), allel1(allel1), allel2(allel2) {

}
Gene::~Gene() {

}
Gene::Gene(const Gene& gene) :
		type(gene.type), allel1(gene.allel1), allel2(gene.allel2) {

}
