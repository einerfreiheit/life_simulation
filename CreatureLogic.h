/*
 * wormlogic.h
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_

class wormlogic
{
public:
    wormlogic(int,int);
    double eat(double);
    void move(bool, int, int);
    int next_x;
    int next_y;

    int size_y;
    int size_x;

    int way;
    enum { down=0,up,left,right};
    bool IsHungry(double);
    bool hungry;

    virtual ~wormlogic();
};

#endif /* CREATURELOGIC_H_ */
