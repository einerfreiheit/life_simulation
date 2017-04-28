#include "CreatureBuilder.h"
#include "GenomeBuilder.h"
#include "../Genetics/GenomeVisualizer.h"
#include "PhenotypeBuilder.h"
#include <iostream>


int CreatureBuilder::nextId = 0;

CreaturePtr CreatureBuilder::build ( World *world, int posX, int posY ) {
    CreaturePtr result = std::shared_ptr<Creature> ( new Creature ( nextId++ ) );
    result->setPosX ( posX );
    result->setPosY ( posY );
    result->setEnergy ( 100 );
    //@ временно пусть будет так
    //@ можешь папку создать и посмотреть на выхлоп
    GenomePtr genome = GenomeBuilder::build ( 15 + rand() % 8 );
    Phenotype *phenotype = PhenotypeBuilder::build ( genome );
    CreaturePtr resultInCell = result;
  
    result->setGenome ( genome );
    result->setPhenotype ( phenotype );

    world->map[posY][posX].creaturesInCell.push_back ( resultInCell );

    cv::Mat vis = GenomeVisualizer::visualize ( genome );
    cv::imwrite ( "genomes/" + std::to_string ( nextId ) + ".png", vis );

    return result;
    }

CreaturePtr  CreatureBuilder::build ( World *world, CreaturePtr parent ) {

    CreaturePtr result = std::shared_ptr<Creature> ( new Creature ( nextId++ ) );
    CreaturePtr resultInCell = result;
    
    int posX=parent->getPosX();
    int posY=parent->getPosY();
    result->setPosX ( posX );
    result->setPosY ( posY );
    result->setEnergy ( 100 );
    GenomePtr genome = GenomeBuilder::build ( parent );
    Phenotype *phenotype = PhenotypeBuilder::build ( genome );

    result->setGenome ( genome );
    result->setPhenotype ( phenotype );

    world->map[posY][posX].creaturesInCell.push_back ( resultInCell );

    cv::Mat vis = GenomeVisualizer::visualize ( genome );
    cv::imwrite ( "genomes/" + std::to_string ( nextId ) + ".png", vis );

    return result;

    }
