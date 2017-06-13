#include "CreatureRemoveWorker.h"
#include <iostream>

CreatureRemoveWorker::CreatureRemoveWorker() {
	this->name = "CreatureRemoveWorker";
}

void CreatureRemoveWorker::work(World *world) {

	int lastId = (int) world->creatures.size() - 1;
	int lastIdBefore = lastId;
	int i = 0;
	while (i <= lastId) {
		CreaturePtr c = world->creatures[i];
		if (c->energy <= 0 || c->phenotype->healthPoints <= 0) {

			int x = c->x;
			int y = c->y;

			int currentId = c->getId();

			Cell &currentCell = world->map[y][x];
			int creaturesInCellNum = currentCell.creaturesInCell.size();
			//@ сделать у cell метод: removeCreature(id)
			//@ можно даже сделать эксептион, если такого ид не найдется

			if (creaturesInCellNum == 1) {
				currentCell.creaturesInCell.clear();
			}
			else {
				for (int j = 0; j < creaturesInCellNum; j++) {
					if (currentCell.creaturesInCell[j]->getId() == currentId) {
						currentCell.creaturesInCell[j] = currentCell.creaturesInCell[creaturesInCellNum - 1];
						currentCell.creaturesInCell.resize(creaturesInCellNum - 1);
					}

				}

			}
			world->creatures[i] = world->creatures[lastId];
			lastId--;

		}
		else {
			i++;
		}
	}
	if (lastId != lastIdBefore) {

		std::cout << world->creatures.size() << " to " << lastId + 1 << std::endl;
		std::cout << "c";
		world->creatures.resize(lastId + 1);
		std::cout << "a";
		for (CreaturePtr creature : world->creatures) {
			std::cout << "b";
			std::cout << creature->getId() << "id " << std::endl;

		}
	}
}
CreatureRemoveWorker::~CreatureRemoveWorker() {
}

