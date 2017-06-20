#include "Move.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
Move::Move(int _dy, int _dx) :
		dy(_dy), dx(_dx) {
	type = AT_MOVE;
}

bool Move::isOutOfBorder(World* world, int nextY, int nextX) {

	return (nextX < 0 || nextX >= world->map[0].size() || nextY < 0 || nextY >= world->map.size());
}

double Move::getNeededEnergy(World *world, Cell *cellFrom, Cell *cellTo, CreaturePtr creature) {
	if (cellFrom->height > cellTo->height) {
		return (cellFrom->height - cellTo->height) * creature->phenotype->energyToClimb
				+ creature->phenotype->energyToMove;
	}
	else {
		return creature->phenotype->energyToMove;
	}
}

void Move::act(World *world, CreaturePtr creature) {
	int nextX = dx + creature->x;
	int nextY = dy + creature->y;
	double energyReq = 0;
	double neededEnergy = 0.0;
	if (isOutOfBorder(world, nextY, nextX)) {
		return;
	}

	Cell *cellFrom = world->getCell(creature->y, creature->x);
	Cell *cellTo = world->getCell(nextY, nextX);
	neededEnergy = getNeededEnergy(world, cellFrom, cellTo, creature);
	if (neededEnergy > creature->energy) {
		return;
	}
	creature->energy-=neededEnergy;
	creature->x=nextX;
	creature->y=nextY;
	move(cellFrom, cellTo, creature->getId());

}

void Move::move(Cell *cellFrom, Cell *cellTo, int id) {
	bool hasBeenMoved=false;
	if (cellFrom->creaturesInCell.empty()) {
		throw std::runtime_error(" Move: departure cell is empty");
	}
	for (size_t i = 0; i < cellFrom->creaturesInCell.size(); i++) {
		if (cellFrom->creaturesInCell[i]->getId() == id) {
			cellTo->creaturesInCell.push_back(cellFrom->creaturesInCell[i]);
			cellFrom->creaturesInCell[i] = cellFrom->creaturesInCell[cellFrom->creaturesInCell.size() - 1];
			hasBeenMoved=true;
			break;

		}
	}

	if (hasBeenMoved){
		cellFrom->creaturesInCell.resize(cellFrom->creaturesInCell.size()-1);
		return;
	}
	else {
		throw std::runtime_error("Move: cannot find creature in departure cell");
	}


}
Move::~Move() {

}

