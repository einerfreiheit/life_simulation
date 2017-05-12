#include "CreatureActionWorker.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
CreatureActionWorker::CreatureActionWorker()
{
  this->name = "CreatureActionWorker";

}

CreatureActionWorker::~CreatureActionWorker()
{
}

void CreatureActionWorker::work ( World *world )
{
  for ( CreaturePtr creature: world->creatures )
    {
      std::cout<<creature->getId() << " creature id"<< std::endl;
      uint8_t gate=0;

      for ( SimpleAction *simpleAction  : creature->creatureActions )
        {
          Action *actionPtr= static_cast<Action*> ( simpleAction );

          if ( gate!= ( gate | actionPtr->getType() ) )
            {
              actionPtr->act ( world,creature );
              gate |=actionPtr->getType();
            }
          delete simpleAction;


        }
      double creatureEnergy = creature->getEnergy()-0.1;
      creature->setEnergy ( creatureEnergy );


      creature->creatureActions.clear();

    }
}

