#include "Creature.h"
Creature::Creature ( int _id ) : id ( _id ) {

    energy = 0.0;
    x = 0;
    y = 0;
    }

void Creature::setPosX ( int setX ) {

    this->x = setX;
    }
void Creature::setPosY ( int setY ) {
    this->y = setY;

    }
int Creature::getPosX() const {

    return this->x;
    }
int Creature::getPosY() const {
    return this->y;

    }

int Creature::getId() const {
    return id;
    }

bool Creature::isHungry() const {

    return this->energy <= lowEnergyLevel;
    }

double Creature::getEnergy() const {
    return this->energy;

    }
void Creature::setEnergy ( double energyToSet ) {
    this->energy = energyToSet;

    }


void Creature::setGenome ( GenomePtr _genome ) {
    this->genome = _genome;
    }

Creature::~Creature() {
    if ( genome ) {
        delete genome;
        }
    }

