#include "CreatureLogic.h"
CreatureLogic::CreatureLogic() {
}
CreatureLogic::~CreatureLogic() {
}

void CreatureLogic::logicActions(World *world, Creature &creature) {

	logicEat(creature);
	int x = creature.getPosX();
	int y = creature.getPosY();
	if (world->map[y][x].food < creature.creatureOneBait) {
		logicMove(world, creature);
	}


}
void CreatureLogic::logicMove(World *world, Creature &creature) {

}
void CreatureLogic::logicEat( Creature &creature) {

}
