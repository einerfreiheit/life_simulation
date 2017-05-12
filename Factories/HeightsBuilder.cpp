#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/DiamondSquare.h"
#include "../Map/Ply.h"

void HeightsBuilder::setDepth ( World*world )
{

  double maxH = world->map[0][0].cellHeight;
  double minH =  world->map[0][0].cellHeight;
  double cellHeight = 0;
  for ( int i = 0; i < world->mapWidth; i++ )
    {
      for ( int j = 0; j < world->mapHeight; j++ )
        {
          cellHeight = world->map[j][i].cellHeight;
          if ( cellHeight > maxH )
            {
              maxH = cellHeight;
            }
          if ( cellHeight < minH )
            {
              minH = cellHeight;
            }
        }
    }
  world->heightsRange = maxH - minH;
  world->maxHeight=maxH;
  world->minHeight=minH;
}

void HeightsBuilder::build ( World* world )
{
  DiamondSquare diamondSquare ( world );
  HeightsBuilder::setDepth ( world );
  Ply ply ( world );
  ply.~Ply();
}
