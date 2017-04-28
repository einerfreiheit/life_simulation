#include "Attack.h"
#include "iostream"

Attack::Attack() {
    type=AT_ATTACK;
    }

Attack::~Attack() {


    }
void Attack::attack ( CreaturePtr aggressor, CreaturePtr victim ) {

    double &victimHealthPoints=victim->phenotype->healthPoints;
    double attackPower= aggressor->phenotype->attackPower;
    victimHealthPoints-=attackPower;
    std::cout<<"creature id: "<<victim->getId() <<"  hp :"<<victim->phenotype->healthPoints<<" attacked by creature id:"<<aggressor->getId() <<std::endl;

    }

void Attack::act ( World* world, CreaturePtr creature ) {
    int x =creature->getPosX();
    int y= creature->getPosY();
    int currentCreature = creature->getId();
    Cell& cell = world->map[y][x];

    int numberOfCreatures =cell.creaturesInCell.size();
    std::cout<<numberOfCreatures<<" number of creatures in"<<y<<" "<<x<<std::endl;


    for ( int i=0; i<numberOfCreatures; i++ ) {
     
        if ( cell.creaturesInCell[i]->getId() !=currentCreature ) {
            attack ( creature, cell.creaturesInCell[i] );
            }


        }

    }

