#include "GenomeBuilder.h"


GenomePtr GenomeBuilder::build ( int complexity ) {
    GenomePtr result = new Genome;
    size_t chromosomesNum = complexity / complexityPerChromosome + ( ( complexity % complexityPerChromosome ) > 0 );
    result->chromosomes.resize ( chromosomesNum );

    for ( size_t i = 0; i < result->chromosomes.size(); i++ ) {
        int usedComplexity = std::min ( complexity, complexityPerChromosome );
        complexity -= usedComplexity;
        ChromosomePtr &chromosome = result->chromosomes[i];//@ очень сильное колдунство - ссылка на указатель, главное ногу не прострелить
        chromosome = new Chromosome;
        chromosome->genes.resize ( usedComplexity );
        }
    return result;
    }
