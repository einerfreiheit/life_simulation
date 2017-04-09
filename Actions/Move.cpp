#include "Move.h"
#include<iostream>

Move::Move(int moveToY,int moveToX) {
	this->dx=moveToX;
	this->dy=moveToY;
}


void Move::act(World *world, Creature &creature) {
	int borderY = world->mapHeight - 1;
	int borderX = world->mapWidth - 1;
	int currentX = creature.getPosX();
	int currentY = creature.getPosY();
	int nextX = currentX;
	int nextY = currentY;
	bool isMoved = false;//@ лучше сделать метод bool canMove(World *world, int nextX, int nextY) и в него внести все проверки
	if (!isMoved && dx > currentX) {
		if (currentX < borderX) {
			nextX++;
			isMoved = true;

		}

	}
	if (!isMoved && dx < currentX) {
		if (currentX > 0) {
			nextX--;
			isMoved = true;

		}

	}
	if (!isMoved && dy > currentY) {
		if (currentY < borderY) {
			nextY++;
			isMoved = true;

		}

	}

	if (!isMoved && dy < currentY) {
		if (currentY > 0) {
			nextY--;
			isMoved = true;

		}

	}

	if (isMoved) {
		creature.energy = creature.energy - SimulationData::getInst()->energyToMove;
		creature.setPosX(nextX);
		creature.setPosY(nextY);

	}

}
Move::~Move() {

//	std::cout<<"move deleted";


}

