#include "AIWorker.h"
#include "Logics/SimpleLogics.h"

AIWorker::AIWorker() {
    this->name = "AIWorker";
    
   simple=new SimpleLogics;

    }

AIWorker::~AIWorker() {

    }

void AIWorker::work ( World *world ) {

    for ( auto creature : world->creatures ) {
	  simple->creatureWill(world,*creature);

        }
    }

