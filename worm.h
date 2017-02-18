/*
 * worm.h
 *
 *  Created on: 17.02.2017
 *      Author: daniil
 */
#ifndef WORM_H_
#define WORM_H_

class worm {
public:
	worm();
	int worm_id;
	int worm_x;
	int worm_y;
	bool worm_hungry;
	int  getAdressY();
	int  getAdressX();
	void createWorm(int,int,int);
	virtual ~worm();
	void eat();
};

#endif /* WORM_H_ */
