#ifndef GENE_H
#define GENE_H

enum GENE_TYPE {
    GT_TRANSLATION=0,
    GT_GROW = 1,
    GT_REGENERATION=2,
    GT_AGRESSION=3,
    GT_ENUM_END = 4
};

class Gene
{
public:
    Gene();
     Gene ( GENE_TYPE type, float allel1, float allel2 );
     Gene (const Gene& gene);
    virtual ~Gene ();
    GENE_TYPE type;
    float allel1;
    float allel2;
};

#endif // GENE_H
