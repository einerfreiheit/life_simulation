#ifndef VISUALIZATION_OPENGLSTATICDATA_H_
#define VISUALIZATION_OPENGLSTATICDATA_H_

#include  "../World.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class OpenGLStaticData  {
public:
	OpenGLStaticData();
	virtual ~OpenGLStaticData();
	GLuint  createData(World *world);
private:
	void getHeightDepth(World *world);
	void getTextureUV(const float &vertexPosX, const float &vertexPosY);
	float minHeight;
	float maxHeight;
	std::vector<float> mapData;

};

#endif
