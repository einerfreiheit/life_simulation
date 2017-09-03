#ifndef OPENGL_OPENGLBUFFERDATA_H_
#define OPENGL_OPENGLBUFFERDATA_H_

#include "../World.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

struct vertex {
	float vertexPosition[3];
	float textureUV[2];

};

enum BUFFER_TYPE {
	BT_STATIC = 0,
	BT_DYNAMIC = 1,
	BT_END = 2
};

class OpenGLBufferData {
public:
	OpenGLBufferData();
	~OpenGLBufferData();
	BUFFER_TYPE type;
	virtual void initBufferData(World *world)=0;
	virtual void computeBufferData(World *world)=0;
	void addCellVertices(Cell *cell, float & vertexZ);
	std::vector<vertex> vertices;
	std::vector<GLuint> indices;
	GLuint verticesToUpdate;
	GLuint indicesToUpate;
	float objectTextureSize;

};

#endif
