#ifndef ACTIONS_MOVE_H_
#define ACTIONS_MOVE_H_

#include "Action.h"

class Move: public Action {
public:
	Move(int _dy, int _dx);
	Move();
	~Move();
	void act(World *world, CreaturePtr creature) override;
private:
	int dx;
	int dy;
	bool isOutOfBorder(World *world, int y, int x);
	double getNeededEnergy(World *world, Cell *cellFrom, Cell *cellTo, CreaturePtr creature);
	void move(Cell *cellFrom, Cell *cellTo, int id);
};

#endif
