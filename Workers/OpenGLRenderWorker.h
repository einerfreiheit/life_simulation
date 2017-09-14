#ifndef WORKERS_OPENGLRENDERWORKER_H_
#define WORKERS_OPENGLRENDERWORKER_H_

#include "../OpenGL/OpenGLRender.h"
#include "WorldWorker.h"

class OpenGLRenderWorker:public WorldWorker {
public:
	OpenGLRenderWorker(World *world);
	virtual ~OpenGLRenderWorker();
	static OpenGLRender *renderer;
	void work(World *world);
};

#endif
