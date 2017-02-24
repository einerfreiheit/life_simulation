/*
 * wormlogic.cpp

 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */
#include "CreatureLogic.h"

#include <cstdlib>

wormlogic::wormlogic(int y,int x)
{
    hungry = false;
    way = -1;
    next_x = 0;
    next_y = 0;
    this->size_y=y;
    this->size_x=x;

}






double wormlogic::eat(double food)
{
    if (food > 10) {
        food = food - 10;
    } else
        food = 0.0;
    return food;
}

bool wormlogic::IsHungry(double food)
{
    if (food == 0)
        hungry = true;

    else
        hungry = false;
    return hungry;
}
void wormlogic::move(bool hungry, int y, int x)
{
    next_x = x;
    next_y = y;
    if (hungry == true) {
        way=rand()%4;
        switch (way){
        	case down:{
				if (y > 0)
		                next_y = y - 1;
		            else
		                next_y = y + 1;
				break;
		        }
        	case up: {
        		if (y < size_y-1)
        		         next_y = y + 1;
        	    else
        		         next_y = y - 1;
        		break;
        	}
        	case left:{
        		 if (x > 0)
        		         next_x = x - 1;
        		  else
        		         next_x = x + 1;
        		 break;
        	}
        	case right:{
        		  if (x < size_x-1)
        		         next_x = x + 1;
        		  else
        		         next_x = x - 1;
        		  break;
        	}
        }
    }
}


wormlogic::~wormlogic()
{
    // TODO Auto-generated destructor stub
}

