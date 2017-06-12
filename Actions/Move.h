#ifndef ACTIONS_MOVE_H_
#define ACTIONS_MOVE_H_

#include "Action.h"

class Move: public Action {
public:

	Move();
	~Move();
	void act(World *world, CreaturePtr creature) override;
	void setXandY(int x, int y);
private:
	int dx;
	int dy;
	bool canMove(World *world, CreaturePtr creature, int nextX, int nextY);
	bool checkBorder(World *world, int nextX, int nextY);
	double energyRequired(double currentHeight, double nextHeight, double energyToCLimb, double energyToMove);

};

#endif
