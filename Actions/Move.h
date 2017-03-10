#ifndef ACTIONS_MOVE_H_
#define ACTIONS_MOVE_H_
#include "Action.h"

class Move :public  Action  {
public:
	Move();
	virtual ~Move();
	void act(World *world, Creature &creature) override;
private:
	int side;
		enum WAY_TYPE {
			WT_DOWN = 0, WT_UP, WT_LEFT, WT_RIGHT
		};
};

#endif
