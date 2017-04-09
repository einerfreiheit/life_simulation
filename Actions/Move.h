#ifndef ACTIONS_MOVE_H_
#define ACTIONS_MOVE_H_
#include "Action.h"

class Move: public Action {
public:

	Move(int moveToY,int moveToX);
	 ~Move();
	void act(World *world, Creature &creature) override;
private:
	int dx;
	int dy;

};

#endif
