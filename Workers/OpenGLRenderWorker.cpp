#include "OpenGLRenderWorker.h"
#include "../OpenGL/OpenGLRender.h"

OpenGLRender * OpenGLRenderWorker::renderer = NULL;

OpenGLRenderWorker::OpenGLRenderWorker(World *world) {
	renderer = new OpenGLRender(world);

}

OpenGLRenderWorker::~OpenGLRenderWorker() {
	if (renderer) {
		delete renderer;
	}
}

void OpenGLRenderWorker::work(World *world) {

	renderer->draw(world);

}
