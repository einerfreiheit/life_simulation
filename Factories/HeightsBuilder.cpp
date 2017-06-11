#include "HeightsBuilder.h"
#include "../SimulationData.h"
#include "../Map/DiamondSquare.h"
#include "../Map/Ply.h"
#include "../Map/MapGeneration.h"

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
	  maxH = std::max(maxH, cellHeight);
	  minH = std::min(minH, cellHeight);
        }
    }
  world->heightsRange = maxH - minH;
  world->maxHeight=maxH;
  world->minHeight=minH;
}

void HeightsBuilder::build ( World* world )
{
  //@ выбор типа генератора мира из конфига
  MapGeneration mapGen;
  mapGen.makeNoise(world);
  //DiamondSquare diamondSquare ( world );//@ переписать diamond square
  HeightsBuilder::setDepth ( world );
  Ply ply ( world );
  ply.~Ply();//@ не делать так никогда вообще
}
