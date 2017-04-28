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
GenomePtr GenomeBuilder::build ( CreaturePtr creature ) {
    GenomePtr parentGenome = creature->getGenome();
    GenomePtr result = new Genome;
    size_t chromosomesNum=parentGenome->chromosomes.size();
    size_t genesNum=0;
    result->chromosomes.resize ( chromosomesNum );

    for ( size_t i = 0; i < chromosomesNum; i++ ) {
        ChromosomePtr &chromosome = result->chromosomes[i];
        chromosome = new Chromosome;
        genesNum=result->chromosomes[i]->genes.size();
        chromosome->genes.resize ( genesNum );
        chromosome->genes=parentGenome->chromosomes[i]->genes;
        //  for (size_t j=0;j<genesNum;j++){

        //result->chromosomes[i]->genes[j]=parentGenome->chromosomes[i]->genes[j];
        //}



        }

    // пока так
    return result;

    }


