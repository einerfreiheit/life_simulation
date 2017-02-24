/*
 * worm.h
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */
#ifndef CREATURE_H_
#define CREATURE_H_

class worm
{
public:
    worm();

    int worm_x;
    int worm_y;
    bool worm_hungry;
    double worm_energy;
    int getAdressY();
    int getAdressX();
    void createWorm( int, int);
    virtual ~worm();
    void eat();
};

#endif /* CREATURE_H_ */
