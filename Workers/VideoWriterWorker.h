/*
 * VideoCapWorker.h
 *
 *  Created on: 23 февр. 2017 г.
 *      Author: lenovo
 */
#include "WorldWorker.h"

#ifndef WORKERS_VIDEOCAPWORKER_H_
#define WORKERS_VIDEOCAPWORKER_H_

class VideoWriterWorker: public WorldWorker {
public:
	VideoWriterWorker();
	cv::VideoWriter writer;
	void work (World *world) override;
	virtual ~VideoWriterWorker();
};

#endif /* WORKERS_VIDEOCAPWORKER_H_ */
