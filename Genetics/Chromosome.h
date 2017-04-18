#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <vector>
#include <cstdlib>
#include "Gene.h"

class Chromosome
{
public:
    Chromosome();
    ~Chromosome();

    std::vector<Gene> genes;
    int position = 0;
};
typedef Chromosome * ChromosomePtr;

#endif // CHROMOSOME_H
