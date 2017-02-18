/*
 * cell.h
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */

#ifndef CELL_H_
#define CELL_H_

class cell {
public:
	cell();
	void getRes();
	double blue;
	int getColor();
	double life_res;
	virtual ~cell();
	bool wormishere = false;
};

#endif /* CELL_H_ */
