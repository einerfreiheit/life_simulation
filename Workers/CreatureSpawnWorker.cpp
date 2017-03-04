/*
 * CreatureSpawnWorker.cpp
 *
 *  Created on: 24 февр. 2017 г.
 *      Author: lenovo
 */

#include "CreatureSpawnWorker.h"
#include <cstdlib>
#include "Creature.h"
#include "../Factories/CreatureBuilder.h"

CreatureSpawnWorker::CreatureSpawnWorker()
{
    this->name = "CreatureSpawnWorker";

}

void CreatureSpawnWorker::work(World *world)
{
    if (!world->creatures.size()) {
        return;
    }
    
    int lastId = (int)world->creatures.size() - 1;
    int i = 0;
    while (i <= lastId) {
        Creature *current = world->creatures[i];
        if (current->getEnergy() <= 0) {
            delete current;
            world->creatures[i] = world->creatures[lastId];
            lastId--;
        }else{
            i++;
        }
    }
    world->creatures.resize(lastId + 1);

    for (int i = 0; i <= lastId; i++){
        Creature *current = world->creatures[i];
        if (current->getEnergy() > energyFissionThreshold) {
            current->setEnergy(current->getEnergy() - lossFromFission);
            Creature *second = CreatureBuilder::build(current->getPosX(), current->getPosY());
            world->creatures.push_back(second);
        }
    }
}

CreatureSpawnWorker::~CreatureSpawnWorker()
{
}

