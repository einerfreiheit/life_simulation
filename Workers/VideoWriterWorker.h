#include "WorldWorker.h"

#ifndef WORKERS_VIDEOCAPWORKER_H_
#define WORKERS_VIDEOCAPWORKER_H_

class VideoWriterWorker: public WorldWorker {
public:
	VideoWriterWorker();
	void work(World *world) override;
	virtual ~VideoWriterWorker();
	void init(World *world);
	bool initDone;
private:
	cv::VideoWriter writer;
	cv::Mat output;


};

#endif /* WORKERS_VIDEOCAPWORKER_H_ */
