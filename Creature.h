#ifndef CREATURE_H_
#define CREATURE_H_
#include "Actions/SimpleAction.h"
#include <vector>

class Creature
{
public:
    Creature(int id);
    virtual ~Creature();
    std::vector <SimpleAction*> creatureActions;

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
    double lossEnergyInIddle=2.5;
    double creatureOneBait = 5.0;
    double energyToMove=5.0;
protected:
    int x;
    int y;
    int id;
};

#endif /* CREATURE_H_ */
