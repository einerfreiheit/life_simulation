#include "DiamondSquare.h"
#include "../SimulationData.h"
#include <cmath>
#include <stdexcept>

DiamondSquare::DiamondSquare(World*world) {

	init(world);
	diamondSquare(world, SimulationData::getInst()->scale);

}

DiamondSquare::~DiamondSquare() {

}

void DiamondSquare::init ( World* world )
{
  int mapHeight = world->map.size();
  int mapWidth = world->map[0].size();

  float cornerHeight = SimulationData::getInst()->cornerHeight;
  int firstStepDecrease = SimulationData::getInst()->firstStepDecrease;
  int lesserSide = std::min ( mapHeight, mapWidth );
  float rawStep = std::log2 ( lesserSide );

  if ( std::abs ( rawStep ) < 0.0001 )
    {
      step = pow ( 2, ( int ) ( rawStep ) - 1 );

    }
  else
    {
      step = pow ( 2, ( int ) std::floor ( rawStep ) );

    }
  if ( step > 0 )
    {
      for ( int y = 0; y < mapHeight; y += step )
        {
          for ( int x = 0; x < mapWidth; x += step )
            {
              world->map[y][x].height = cornerHeight;

            }
        }
    }
  int firstStepDecerease = SimulationData::getInst()->firstStepDecrease;
  if ( firstStepDecrease==1 || ( ( firstStepDecerease & ( firstStepDecerease - 1 ) ) ==0 ) )
    {
      step = step / firstStepDecrease;

    }
  else
    {
      throw std::runtime_error ( "firstStepDecrease must be 1 or power of 2 " );
    }
  if ( lesserSide<=1 )
    {
      throw std::runtime_error ( "world's sides size must be greater than 1" );
    }
}

void DiamondSquare::diamondStep ( World *world, int y, int x, double range )
{
  Cell &cell = world->map[y][x];
  double sumOfHeights = 0;
  int pointCount=0;

  int leftPointX=x-step/2;
  int rightPointX=x+step/2;
  int upperPointY=y+step/2;
  int lowerPointY=y-step/2;

  if ( checkIndex ( leftPointX,world->map[0].size() ) )
    {
      sumOfHeights += world->map[y][leftPointX].height;
      pointCount++;
    }
  if ( checkIndex ( rightPointX,world->map[0].size()) )
    {
      sumOfHeights += world->map[y][rightPointX].height;
      pointCount++;
    }
  if ( checkIndex ( upperPointY,world->map.size()))
    {
      sumOfHeights += world->map[upperPointY][x].height;
      pointCount++;
    }
  if ( checkIndex ( lowerPointY,world->map.size() ) )
    {
      sumOfHeights += world->map[lowerPointY][x].height;
      pointCount++;
    }


  cell.height = sumOfHeights / pointCount + range * rangedRandom();
}

bool  DiamondSquare::checkIndex ( int index, int size )
{
  return ( index>=0 && index<size );


}
void DiamondSquare::squareStep ( World *world, int y, int x, double scale )
{

  double sumOfHeights = world->map[y][x].height;
  sumOfHeights += world->map[y + step][x].height;
  sumOfHeights += world->map[y][x + step].height;
  sumOfHeights += world->map[y + step][x + step].height;
  world->map[y + step / 2][x + step / 2].height = ( sumOfHeights ) / 4
      + rangedRandom() * scale;

}

void DiamondSquare::diamondSquare ( World*world, double scale )
{
  if ( step < 2 )
    {
      return;
    }
  int borderY = world->map.size() - step;
  int borderX = world->map[0].size() - step;

  for ( int i = 0; i < borderY; i += step )
    for ( int j = 0; j < borderX; j += step )
      {
        squareStep ( world, i, j, scale );

      }

  borderY= world->map.size();
  borderX= world->map[0].size()-step/2;
  for ( int i = 0; i < borderY; i += step )
    {
      for ( int j = step / 2; j < borderX; j += step )
        {
          diamondStep ( world, i, j, scale );
        }
    }
  borderY= world->map.size()-step/2;
  borderX = world->map[0].size();
  for ( int i = step / 2; i < borderY; i += step )
    {
      for ( int j = 0; j < borderX; j += step )
        {

          diamondStep ( world, i, j, scale );

        }
    }

  step /= 2;
  scale /= SimulationData::getInst()->smooth;
  diamondSquare ( world, scale );

}

double DiamondSquare::rangedRandom()
{
  return 2 * ( double ) rand() / RAND_MAX - 1;

}
