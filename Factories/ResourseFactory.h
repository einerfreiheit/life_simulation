
#ifndef RESOURSEFACTORY_H
#define RESOURSEFACTORY_H
#include "../World.h"

class ResourseFactory
{
public:
    static void addWater(World * world);
   static  double amountOfWater;

   static  void waterFlow(World *world);
    
};

#endif // RESOURSEFACTORY_H
