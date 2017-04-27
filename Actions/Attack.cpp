#include "Attack.h"
#include "iostream"

Attack::Attack() {
    type=AT_ATTACK;
    }

Attack::~Attack() {


    }
void Attack::attack ( CreaturePtr actor, CreaturePtr victim ) {
    double &victimHealthPoints=victim->phenotype->healthPoints;
    double attackPower= actor->phenotype->attackPower;
    victimHealthPoints-=attackPower;
    std::cout<<" hp :"<<victim->phenotype->healthPoints<<std::endl;
    
    }

void Attack::act ( World* world, CreaturePtr creature ) {
    int x = creature->getPosX();
    int y= creature->getPosY();
    int currentCreature = creature->getId();
    Cell& cell = world->map[y][x];

    int numberOfCreatures =cell.creaturesInCell.size();
    for ( int i=0; i<numberOfCreatures; i++ ) {
        if ( cell.creaturesInCell[i]->getId() !=currentCreature ) {
            attack ( creature,cell.creaturesInCell[i] );

            }


        }

    }

