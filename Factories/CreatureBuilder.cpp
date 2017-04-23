#include "CreatureBuilder.h"
#include "GenomeBuilder.h"
#include "../Genetics/GenomeVisualizer.h"
#include "PhenotypeBuilder.h"

int CreatureBuilder::nextId = 0;

Creature *CreatureBuilder::build ( int posX, int posY ) {
    Creature *result = new Creature ( nextId++ );
    result->setPosX ( posX );
    result->setPosY ( posY );
    result->setEnergy ( 100 );


    //@ временно пусть будет так
    //@ можешь папку создать и посмотреть на выхлоп
    GenomePtr genome = GenomeBuilder::build ( 15 + rand() % 8 );
    Phenotype *phenotype = PhenotypeBuilder::build(genome);
    
    result->setGenome ( genome );
    result->setPhenotype(phenotype);
    cv::Mat vis = GenomeVisualizer::visualize ( genome );
    cv::imwrite ( "genomes/" + std::to_string ( nextId ) + ".png", vis );

    return result;
    }
