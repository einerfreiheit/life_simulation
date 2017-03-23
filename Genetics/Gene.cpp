#include "Gene.h"
#include "GeneticsUtils.h"
#include <stdlib.h>

Gene::Gene()
{
    type = static_cast<GENE_TYPE>(rand() % GT_ENUM_END);
    value1 = GeneticsUtils::rangedRandom(-1, 1);
    value2 = GeneticsUtils::rangedRandom(-1, 1);
}

Gene::Gene(GENE_TYPE type, float value1, float value2) : type(type), value1(value1), value2(value2)
{

}
