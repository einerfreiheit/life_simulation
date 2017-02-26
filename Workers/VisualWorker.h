#ifndef WORKERS_VISUALWORKER_H_
#define WORKERS_VISUALWORKER_H_
#include "WorldWorker.h"


class VisualWorker : public WorldWorker {
public:
	VisualWorker();
	virtual ~VisualWorker();
	void work (World *world) override;
	void computingImage(World *world);
	void showImage(World *world);
	std::vector<Creature> worm_map ;
	std::vector<std::vector<Cell> > map;
	 int mapHeight;
	 int mapWidth;
private:
    void getImageNICE(World *world);
};

#endif /* WORKERS_VISUALWORKER_H_ */
