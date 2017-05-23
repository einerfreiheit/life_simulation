#include "MapGeneration.h"
#include <iostream>
MapGeneration::MapGeneration()
{

}
void MapGeneration::makeNoise ( World* world )
{
  for (int y=0;y<world->mapHeight;y++){
         for (int x=0;x<world->mapWidth;x++){
	   double nx=(double)x/world->mapWidth;
	   double ny=(double)y/world->mapHeight;
	   double height= nx+ny-1.0;
	   world->map[y][x].cellHeight=height;
	   std::cout<<world->map[y][x].cellHeight<<' ';
       
      
    }
    
    
  }
}

MapGeneration::~MapGeneration()
{

}
