#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_
#include "WorldWorker.h"


class VisualWorker : public WorldWorker {
public:
	VisualWorker();
	virtual ~VisualWorker();
	void work (World *world) override;
	void getImage(World *world);//@ опять в имени метода есть слово get, а он возвращает void
	void showImage(World *world);
	std::vector<worm> worm_map ;
	std::vector<std::vector<cell> > map;
	 int mapHeight;
	 int mapWidth;
private:
    void getImageNICE(World *world);
};

#endif /* WORKERS_VISUALWORKER_H_ */
