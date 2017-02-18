/*
 * wormlogic.h
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */

#ifndef WORMLOGIC_H_
#define WORMLOGIC_H_

class wormlogic {
public:
	wormlogic();
	double eat(double);
	void move(bool,int,int,int,int);
	int next_x;
	int next_y;
	int way;
	bool IsHungry(double);
	bool hungry;

	virtual ~wormlogic();
};

#endif /* WORMLOGIC_H_ */
