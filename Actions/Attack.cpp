#include "Attack.h"
#include "iostream"

Attack::Attack() {
	type = AT_ATTACK;
}

Attack::~Attack() {
}

void Attack::attack(CreaturePtr aggressor, CreaturePtr victim) {
	victim->phenotype->healthPoints -= aggressor->phenotype->attackPower;
	std::cout << "creature id: " << victim->getId() << "  hp :" << victim->phenotype->healthPoints
			<< " attacked by creature id:" << aggressor->getId() << std::endl;
	victim->hasBeenAttacked = true;

}

void Attack::act(World* world, CreaturePtr creature) {

	int id = creature->getId();
	Cell& cell = *world->getCell(creature->y,creature->x);

	int numberOfCreatures = cell.creatures.size();
	std::cout << numberOfCreatures << " number of creatures in " << creature->y << " " << creature->x << std::endl;
	for (auto otherCreature : cell.creatures) {
		if (otherCreature->getId() != id) {
			attack(creature, otherCreature);
			creature->stats->incrementAttacksNumber();
			return;
		}

	}

}

