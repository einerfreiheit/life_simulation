#ifndef GENE_H
#define GENE_H

enum GENE_TYPE {
    GT_AFFINITY = 0,
    GT_DURABILITY = 1,
    GT_SYNTHESIS = 2,
    GT_MOVABILITY = 3,
    GT_MEMORY = 4,
    GT_VISION = 5,
    GT_CONSUMESY = 6,
    GT_REGENERATION = 7,
    GT_TASTE = 8,
    GT_TOXICITY = 9,
    GT_CAMOUFLAGE = 10,
    GT_SCENT = 11,
    GT_ECONOMY = 12,
    GT_COMPLEXITY = 13,
    GT_ENUM_END = 14
};

class Gene
{
public:
    Gene();
    Gene ( GENE_TYPE type, float allel1, float allel2 );

    GENE_TYPE type;
    float allel1;
    float allel2;
};

#endif // GENE_H
