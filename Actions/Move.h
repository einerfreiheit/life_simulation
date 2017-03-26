#ifndef ACTIONS_MOVE_H_
#define ACTIONS_MOVE_H_
#include "Action.h"

class Move: public Action {
public:

	Move();
	virtual ~Move();
	void act(World *world, Creature &creature) override;
	int dx;
	int dy;

};

#endif
