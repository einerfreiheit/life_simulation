#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <vector>
#include "Gene.h"
#include <memory>

class Chromosome
{
public:
    Chromosome();
    ~Chromosome();

    std::vector<Gene> genes;
    int position = 0;
};
typedef std::shared_ptr<Chromosome> ChromosomePtr;

#endif // CHROMOSOME_H
