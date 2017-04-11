/*
 * VisualVideoWorker.h
 *
 *  Created on: 12.04.2017
 *      Author: daniil
 */

#ifndef WORKERS_SUBWORKERS_VISUALVIDEOWORKER_H_
#define WORKERS_SUBWORKERS_VISUALVIDEOWORKER_H_
#include "VisualSubWorker.h"

class VisualVideoWorker: public VisualSubWorker {
public:
	VisualVideoWorker();
	virtual ~VisualVideoWorker();
	void work(cv::Mat* visualization) override;

private:
	cv::VideoWriter writer;
	cv::Mat output;

};

#endif /* WORKERS_SUBWORKERS_VISUALVIDEOWORKER_H_ */
