#ifndef OPENGLWORLDRENDERER_H
#define OPENGLWORLDRENDERER_H

#include <WorldWorker.h>

class OpenGLWorldRenderer : public  WorldWorker
{
public:
  OpenGLWorldRenderer();
  
  virtual void work(World* world);
};

#endif // OPENGLWORLDRENDERER_H
