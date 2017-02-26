/*
 * worm.h
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */
#ifndef CREATURE_H_
#define CREATURE_H_

class Creature {
public:
	Creature();
	virtual ~Creature();
	int x;
	int y;
	bool isHungry();
	double energy;
	bool getHungry();
	double getEnergy();
	double lowEnergyLevel=50.0;
	int getPosY();
	int getPosX();
	void setPosY(int setY);
	void setPosX(int setX);
	void setEnergy(double energyToSet);



};

#endif /* CREATURE_H_ */
