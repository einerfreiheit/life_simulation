#include "WorldWorker.h"

#ifndef WORKERS_VIDEOCAPWORKER_H_
#define WORKERS_VIDEOCAPWORKER_H_

class VideoWriterWorker: public WorldWorker {
public:
	VideoWriterWorker();
	void work (World *world) override;
	virtual ~VideoWriterWorker();
	cv::Mat output;

private:cv::VideoWriter writer;
};

#endif /* WORKERS_VIDEOCAPWORKER_H_ */
