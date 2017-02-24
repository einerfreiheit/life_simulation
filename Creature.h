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

    int worm_x;//@ такое наименование переменных избыточно. Итак известно, что работаем с классом Worm, и поля worm_x, worm_что_угодно - лишняя графомания
    int worm_y;//@ графоманить можно тогда, когда неочевидно, что означает поле: pos_x, target_x, next_x
    bool worm_hungry;
    double worm_energy;
    int getAdressY();//adress - не слишком удачное слово. 1: там на самом деле две буквы Д, 2: лучше слово Position или Pos использовать
    int getAdressX();
    void createWorm( int, int);//@ в том случае, когда переменные что-то означают, имеет смысл оставлять им имена даже внутри объявления метода
    virtual ~worm();
    void eat();
};

#endif /* CREATURE_H_ */
