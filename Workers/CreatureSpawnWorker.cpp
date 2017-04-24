#include "CreatureSpawnWorker.h"
#include <iostream>
CreatureSpawnWorker::CreatureSpawnWorker() {
    this->name = "CreatureSpawnWorker";

    }

void CreatureSpawnWorker::work ( World *world ) {

    for ( Creature *creature : world->creatures ) {
        if ( creature->getEnergy() > creature->phenotype->fissionThreshold) {
            creature->setEnergy ( creature->getEnergy() - creature->phenotype->fissionLoss );
      //      Creature *second = CreatureBuilder::build (creature->getPosX(),creature->getPosY());
	      Creature *second = CreatureBuilder::build (*creature);
            world->creatures.push_back ( second );
            }
        }
    }

CreatureSpawnWorker::~CreatureSpawnWorker() {
    }

