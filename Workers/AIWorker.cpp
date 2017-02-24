#include "AIWorker.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>


AIWorker::AIWorker()
{
    this->name = "AIWorker";
}

AIWorker::~AIWorker()
{

}

void AIWorker::work(World *world)
{
    

    for (int i = 0; i < world->worm_map.size(); i++) {
    	int x = world->worm_map[i].getAdressX();
    	int y = world->worm_map[i].getAdressY();
    	ishungry(world,y,x,i);
    	move(world,y,x,i);
    	eat(world,y,x,i);
    	std::cout<<world->worm_map[i].worm_energy<<std::endl;
    	if (Alive(world,i)==false){
    		world->worm_map.erase(world->worm_map.begin()+i);
    		std::vector <worm>(world->worm_map).swap(world->worm_map);


    	}

    }
}


bool AIWorker::ishungry(World *world,int y,int x,int i){//@ лучше назвать метод isHungry (каждое слово с большой буквы, кроме первого

	if (world->map[y][x].life_res==0.0){
		hungry=true;
	}
	else hungry=false;

	world->worm_map[i].worm_hungry=hungry;
	return hungry;

}

bool AIWorker::Alive(World *world,int i){//@ лучше назвать метод isAlive и подавать туда сразу червя
	alive = true;
	if (world->worm_map[i].worm_energy<=0){
		alive=false;

	}
	return alive;

}

void AIWorker::move(World *world,int y,int x,int i){
//@ логику червей лучше вынести в отдельный класс всё-таки, тогда будет возможность делать червей с разной логикой
	    if (world->worm_map[i].worm_hungry == true) {
	        way=rand()%4;
	        switch (way){
	        	case down:{
					if (y > 0)
			                y = y - 1;
			            else
			                y = y + 1;
					break;
			        }
	        	case up: {
	        		if (y < world->mapHeight-1)
	        		         y = y + 1;
	        	    else
	        		         y = y - 1;
	        		break;
	        	}
	        	case left:{
	        		 if (x > 0)
	        		         x = x - 1;
	        		  else
	        		         x = x + 1;
	        		 break;
	        	}
	        	case right:{
	        		  if (x < world->mapWidth-1)
	        		         x = x + 1;
	        		  else
	        		         x = x - 1;
	        		  break;
	        	}
	        }
	    }

	    world->worm_map[i].worm_x = x;
	    world->worm_map[i].worm_y = y;
	    world->worm_map[i].worm_energy=world->worm_map[i].worm_energy-1;
}
void AIWorker::eat(World *world,int y,int x,int i){

	if (world->map[y][x].life_res >10.0){
		world->map[y][x].life_res=-10.0;
		world->worm_map[i].worm_energy=world->worm_map[i].worm_energy+10;

	}
	else
		world->map[y][x].life_res=0.0;



}//@ научись пользоваться хотя бы автоформаттером кода. В эклипсе горячие клавиши Ctrl+Shift+F
