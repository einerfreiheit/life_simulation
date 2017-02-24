/*
 * VideoCapWorker.h
 *
 *  Created on: 23 февр. 2017 г.
 *      Author: lenovo
 */
#include "WorldWorker.h"

#ifndef WORKERS_VIDEOCAPWORKER_H_
#define WORKERS_VIDEOCAPWORKER_H_

class VideoCapWorker: public WorldWorker {//@ надо класс переименовать, он не захватывает видео, а записывает
public:
	VideoCapWorker(World *world);
	cv::VideoWriter writer;
	void work (World *world) override;
	virtual ~VideoCapWorker();
};

#endif /* WORKERS_VIDEOCAPWORKER_H_ */
