#include "AIWorker.h"

#include "../CreatureLogic.h"

AIWorker::AIWorker()
{
    this->name = "AIWorker";
}

AIWorker::~AIWorker()
{

}

void AIWorker::work(World *world)
{
    std::vector<worm> &worm_map = world->worm_map;
    std::vector<std::vector<cell> > &map = world->map;
    
    wormlogic logic(world->getHeight(),world->getWidth());
    for (int i = 0; i < worm_map.size(); i++) {

        int x = worm_map[i].getAdressX();
        int y = worm_map[i].getAdressY();

        map[y][x].life_res = logic.eat(map[y][x].life_res);

        logic.move(logic.IsHungry(map[y][x].life_res), y, x);
        x = logic.next_x;
        y = logic.next_y;
        worm_map[i].worm_hungry = logic.IsHungry(map[y][x].life_res);
        worm_map[i].worm_x = x;
        worm_map[i].worm_y = y;
    }
}
