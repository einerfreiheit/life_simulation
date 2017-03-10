/*
 * worm.h
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */
#ifndef CREATURE_H_
#define CREATURE_H_

class Creature
{
public:
    Creature(int id);
    virtual ~Creature();
    bool isHungry() const;
    double energy;
    double lowEnergyLevel = 100.0;
    int getPosY() const;
    int getPosX() const;
    void setPosY(int setY);
    void setPosX(int setX);
    void setEnergy(double energyToSet);
    double getEnergy() const;
    int getId() const;
    double energyFromFood = 10;
    double creatureOneBait = 5.0;
    double energyToMove=5.0;
protected:
    int x;
    int y;
    int id;
};

#endif /* CREATURE_H_ */
