/*
 * VisualDisplayWorker.h
 *
 *  Created on: 12.04.2017
 *      Author: daniil
 */

#ifndef WORKERS_SUBWORKERS_VISUALDISPLAYWORKER_H_
#define WORKERS_SUBWORKERS_VISUALDISPLAYWORKER_H_
#include "VisualSubWorker.h"
class VisualDisplayWorker :public VisualSubWorker {
public:
	VisualDisplayWorker();
	virtual ~VisualDisplayWorker();
	void work(cv::Mat* visualization)override;
};

#endif /* WORKERS_SUBWORKERS_VISUALDISPLAYWORKER_H_ */
