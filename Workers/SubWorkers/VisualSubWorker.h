/*
 * VisualSubWorker.h
 *
 *  Created on: 12.04.2017
 *      Author: daniil
 */

#ifndef WORKERS_SUBWORKERS_VISUALSUBWORKER_H_
#define WORKERS_SUBWORKERS_VISUALSUBWORKER_H_
#include "../../CommonIncludes.h"
class VisualSubWorker {
public:
	VisualSubWorker();
	virtual ~VisualSubWorker();
	virtual void work(cv::Mat* visualization) =0;

};

#endif /* WORKERS_SUBWORKERS_VISUALSUBWORKER_H_ */
