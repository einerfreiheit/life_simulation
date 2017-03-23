#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <vector>
#include "Gene.h"

class Chromosome
{
public:
    Chromosome();
    ~Chromosome();
    
    std::vector<Gene> genes;
    int position = 0;
};

#endif // CHROMOSOME_H
