#include "CreatureRemoveWorker.h"
#include <iostream>
CreatureRemoveWorker::CreatureRemoveWorker() {
    this->name = "CreatureRemoveWorker";
    }

void CreatureRemoveWorker::work ( World *world ) {

    int lastId =  world->creatures.size() - 1;
    int lastIdBefore=lastId;
    int i = 0;
    while ( i <= lastId ) {

        if ( world->creatures[i]->getEnergy() <= 0 || world->creatures[i]->phenotype->healthPoints<=0 ) {

            int x=world->creatures[i]->getPosX();
            int y=world->creatures[i]->getPosY();
	    
            int currentId= world->creatures[i]->getId();
	    
            Cell &currentCell = world->map[y][x];
	    currentCell.food+=world->creatures[i]->phenotype->corpseSize;

            int creaturesInCellNum=currentCell.creaturesInCell.size();
	    
            if ( creaturesInCellNum==1 ) {
		currentCell.creaturesInCell.clear();
                }
            else {
                for ( int j=0; j<creaturesInCellNum; j++ ) {
                    if (currentCell.creaturesInCell[j]->getId() ==currentId ) {
                        currentCell.creaturesInCell[j]= currentCell.creaturesInCell[creaturesInCellNum-1];
                        currentCell.creaturesInCell.resize ( creaturesInCellNum-1 );
                        }

                    }


                }
            world->creatures[i] = world->creatures[lastId];
            lastId--;


            }
        else {
            i++;
            }
        }
    if ( lastId != lastIdBefore ) {

        std::cout<<world->creatures.size() <<" to "<<lastId+1<<std::endl;
        world->creatures.resize ( lastId + 1 ); //@ надо почитать или протестировать ресайз. Что будет, если ресайз идёт к тому же самому размеру? Медленно ли это?
        for ( CreaturePtr creature: world->creatures ) {
            std::cout<< creature->getId() <<"id "<<std::endl;

            }
        }
    }
CreatureRemoveWorker::~CreatureRemoveWorker() {
    }

