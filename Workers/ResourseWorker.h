#ifndef WORKERS_RESOURSEWORKER_H_
#define WORKERS_RESOURSEWORKER_H_
#include "WorldWorker.h"

class ResourseWorker: public WorldWorker {
public:
	ResourseWorker();
	virtual ~ResourseWorker();
    void work(World *world) override;
    double gainResourse =0.0;
    void setGainResourse(double gainResoureToSet);
    int numberOfGainCell;
    void setNuberOfCellToGainResourses (int numberOfCellToGain);
	void setRandomXY(World* world);
    int rand_y;
    int rand_x;


};

#endif /* WORKERS_RESOURSEWORKER_H_ */
