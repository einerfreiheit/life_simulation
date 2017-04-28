#include "CreatureSpawnWorker.h"
#include <iostream>
#include <stdexcept>
CreatureSpawnWorker::CreatureSpawnWorker() {
    this->name = "CreatureSpawnWorker";

    }

void CreatureSpawnWorker::work ( World *world ) {

    for ( CreaturePtr creature : world->creatures ) {
        if ( creature->getEnergy() > creature->phenotype->fissionThreshold ) {
            std::cout<<creature->getId() <<" ready to fission";
            creature->setEnergy ( creature->getEnergy() - creature->phenotype->fissionLoss );
            //     CreaturePtr second = CreatureBuilder::build (creature->getPosX(),creature->getPosY());
            CreaturePtr second = CreatureBuilder::build ( world,creature );	    
            world->creatures.push_back ( second );
	    
            //    std::cout<<world->creatures.size()<< std::endl;
            if ( world->creatures.size() >=100 ) {
                throw std::runtime_error ( "creatures more than 100" );
                }

            }
        }
    }

CreatureSpawnWorker::~CreatureSpawnWorker() {
    }

