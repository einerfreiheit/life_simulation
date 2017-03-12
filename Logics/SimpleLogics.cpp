#include "SimpleLogics.h"
#include "CreatureLogic.h"

SimpleLogics::SimpleLogics() {
this->actions.reserve(2);//@ резервировать малые размеры тут нет особого смысла
//@ есть смысл резервировать тогда, когда много раз этот код будет запускаться, и каждый раз в вектор будет писаться много всего
}
void SimpleLogics::findFood(World*world,Creature& creature){
	int y = creature.getPosY();
	int x = creature.getPosX();
	Cell &cell = world->map[y][x];
	if (cell.food > creature.creatureOneBait) {
		this->actions.push_back(new Eat);
	}
	else {
		this->actions.push_back(new Move);
	}


}

std::vector <Action *> SimpleLogics:: getActions(){
	return this->actions;



}
SimpleLogics::~SimpleLogics() {

}

