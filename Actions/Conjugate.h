#ifndef CONJUGATE_H
#define CONJUGATE_H

#include "Action.h"

class Conjugate: public Action {
public:
	Conjugate();
	~Conjugate();
	void act(World *world, CreaturePtr creature) override;
private:
	void conjugate(CreaturePtr donor, CreaturePtr recipient);
	bool canConjugate(CreaturePtr recipient);
};

#endif
