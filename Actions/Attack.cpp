#include "Attack.h"
#include "iostream"

Attack::Attack() {
	type = AT_ATTACK;
}

Attack::~Attack() {
}

void Attack::attack(CreaturePtr aggressor, CreaturePtr victim) {

	double &victimHealthPoints = victim->phenotype->healthPoints;//@ суперсокращение
	double attackPower = aggressor->phenotype->attackPower;//@ и тут тоже
	victimHealthPoints -= attackPower;
	std::cout << "creature id: " << victim->getId() << "  hp :" << victim->phenotype->healthPoints
			<< " attacked by creature id:" << aggressor->getId() << std::endl;
	victim->hasBeenAttaked = true;

}

void Attack::act(World* world, CreaturePtr creature) {

	int id = creature->getId();
	Cell& cell = world->map[creature->y][creature->x];//@ геттер

	int numberOfCreatures = cell.creaturesInCell.size();
	std::cout << numberOfCreatures << " number of creatures in " << creature->y << " " << creature->x << std::endl;
	for (auto otherCreature : cell.creaturesInCell) {//@ геноцид при большом числе червей в клетке
		if (otherCreature->getId() != id) {
			attack(creature, otherCreature);
			creature->stats->incrementAttacksNumber();
		}

	}

}

