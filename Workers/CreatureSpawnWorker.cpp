#include "CreatureSpawnWorker.h"
#include"../SimulationData.h"
CreatureSpawnWorker::CreatureSpawnWorker() {
    this->name = "CreatureSpawnWorker";

    }

void CreatureSpawnWorker::work ( World *world ) {

    for ( Creature *creature : world->creatures ) {
        if ( creature->getEnergy() > SimulationData::getInst()->fissionThreshold ) {
            creature->setEnergy ( creature->getEnergy() - SimulationData::getInst()->fissionLoss );
            Creature *second = CreatureBuilder::build ( creature->getPosX(),
                               creature->getPosY() );
            world->creatures.push_back ( second );
            }
        }
    }

CreatureSpawnWorker::~CreatureSpawnWorker() {
    }

