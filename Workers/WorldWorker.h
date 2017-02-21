#ifndef WORLDWORKER_H
#define WORLDWORKER_H

#include "../World.h"

class WorldWorker
{
public:
    virtual void work(World *world) = 0;
    
    std::string getName() const;
protected:
    std::string name;
};

#endif // WORLDWORKER_H
