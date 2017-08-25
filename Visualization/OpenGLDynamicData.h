#ifndef VISUALIZATION_OPENGLDYNAMICDATA_H_
#define VISUALIZATION_OPENGLDYNAMICDATA_H_

#include  "../World.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class OpenGLDynamicData {
public:
	OpenGLDynamicData(World *world);
	virtual ~OpenGLDynamicData();

	void updateBuffers(World *world);

	GLuint waterBuffer;
	GLuint creaturesBuffer;
	GLuint waterIBO;

	std::vector<float> water;
	std::vector<float> creatures;
	std::vector<float> waterBufferData;

	std::vector <GLuint> waterIndices;
	GLuint waterIndex;


private:
	void getTextureUV(const float &vertexPosX, const float &vertexPosY);
	float textureCoefficient = 1/128.0;

};

#endif
