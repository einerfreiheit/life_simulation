#ifndef VISUALIZATION_OPENGLDYNAMICDATA_H_
#define VISUALIZATION_OPENGLDYNAMICDATA_H_

#include  "../World.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class OpenGLDynamicData {
public:
	OpenGLDynamicData();
	virtual ~OpenGLDynamicData();

	void updateBuffers(World *world);

	GLuint waterBuffer;
	GLuint creaturesBuffer;

	std::vector<float> water;
	std::vector<float> creatures;
private:
	void getTextureUV(const float &vertexPosX, const float &vertexPosY);

};

#endif
