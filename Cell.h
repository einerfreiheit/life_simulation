#ifndef CELL_H_
#define CELL_H_
#include "Creature.h"
#include <vector>
class Cell
{
public:
    Cell();
    double food;
    double water=0;
    virtual ~Cell();
    double cellHeight=0;

    std::vector<CreaturePtr> creaturesInCell;


};

#endif
