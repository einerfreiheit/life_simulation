/*
 * cell.h
 *
 *  Created on: 16.02.2017
 *      Author: daniil
 */

#ifndef CELL_H_
#define CELL_H_

class cell
{
public:
    cell();
    void getRes();//@ слово get подразумевает, что что-то должно возвращаться из метода, а метод возвращает void, то есть ничего. Нужно другое имя
    double life_res;
    virtual ~cell();
};

#endif /* CELL_H_ */
