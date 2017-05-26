#include "SimpleLogics.h"
#include "../Actions/Eat.h"
#include "../Actions/Move.h"
#include "../Actions/Attack.h"
#include <iostream>

void SimpleLogics::willToEat ( CreaturePtr creature )
{
  creature->creatureActions.push_back ( new Eat );

}


void SimpleLogics::creatureWill ( World* world,CreaturePtr creature )
{
  willToAttack ( creature );
  willToEat ( creature );

  if ( creature->hasBeenAttaked && creature->phenotype->healthPoints<=50 )
    {
      willToMove ( world,creature );
    }
  else
    {
      int x = creature->getPosX();
      int y = creature->getPosY();

      if ( world->map[y][x].food <= creature->phenotype->creatureOneBait )
        {
          willToMove ( world, creature );
        }

    }
  creature->hasBeenAttaked=false;
}
void SimpleLogics::willToAttack ( CreaturePtr creature )
{
  if (creature->phenotype->isAggresive)
  creature->creatureActions.push_back ( new Attack );

}

void SimpleLogics::willToMove ( World *world,CreaturePtr creature )
{

  int y = creature->getPosY();
  int x = creature->getPosX();
  int  side = rand() % 4;
  switch ( side )
    {
    case 0:
    {
      y--;
      break;
    }
    case 1:
    {
      y++;
      break;
    }
    case 2:
    {
      x--;
      break;
    }
    case 3:
    {
      x++;
      break;
    }

    }


  Move *movePtr= new Move;
  movePtr->setXandY ( x,y );
  creature->creatureActions.push_back ( movePtr );

}

