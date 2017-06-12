#include "Move.h"
#include <cmath>
#include <iostream>

Move::Move() {
	type = AT_MOVE;
}

void Move::setXandY(int x, int y) //@ фигачить в конструкторе, навести порядок в именах
					{
	dx = x;
	dy = y;

}

bool Move::checkBorder(World* world, int nextX, int nextY) //@ лучше говорящие названия делать, вроде isOutOfBorder
						{
	int borderY = world->mapHeight;
	int borderX = world->mapWidth;
	return !(nextX < 0 || nextX >= borderX || nextY < 0 || nextY >= borderY);
}

double Move::energyRequired(double currentHeight, double nextHeight, double energyToClimb, double energyToMove) //@ getNeedeEnergy
							{
	return (currentHeight < nextHeight) ? ((nextHeight - currentHeight) * energyToClimb + energyToMove) : energyToMove; //@ лучше if, выражение большое
}

void Move::act(World *world, CreaturePtr creature) {
	double energyReq = 0;
	if (checkBorder(world, dx, dy)) //@ сделать if (isOutOfBorder) return;
					{
		int currentX = creature->getPosX();
		int currentY = creature->getPosY();

		int creatureId = creature->getId();
		double currentHeight = world->map[currentY][currentX].cellHeight;
		double nextHeight = world->map[dy][dx].cellHeight;
		double energyToClimb = creature->phenotype->energyToClimb;
		double energyToMove = creature->phenotype->energyToMove;
		energyReq = energyRequired(currentHeight, nextHeight, energyToClimb, energyToMove);

		if (energyReq <= creature->getEnergy()) //@ сделать if (energyReq > getEnergy) return;
				{
			creature->setEnergy(creature->getEnergy() - energyReq);
			creature->setPosX(dx);
			creature->setPosY(dy);

			//@ вынести перемещение из клетки в клетку по id в метод move(cellFrom, cellTo, id)
			Cell &currentCell = world->map[currentY][currentX];
			Cell &nextCell = world->map[dy][dx];
			int creaturesInCurrentCellSize = currentCell.creaturesInCell.size();
			if (currentCell.creaturesInCell.size() > 1) {
				for (int i = 0; i < creaturesInCurrentCellSize; i++) {
					if (creatureId == currentCell.creaturesInCell[i]->getId()) {
						nextCell.creaturesInCell.push_back(currentCell.creaturesInCell[i]);

						currentCell.creaturesInCell[i] = currentCell.creaturesInCell[creaturesInCurrentCellSize - 1];
						currentCell.creaturesInCell.resize(creaturesInCurrentCellSize - 1);
						break;

					}

				}
			}
			else {

				nextCell.creaturesInCell.push_back(currentCell.creaturesInCell[0]);
				currentCell.creaturesInCell.resize(0);

			}

		}
		else {
			return;
		}

	}
	else {
		return;
	}
}

Move::~Move() {

}

