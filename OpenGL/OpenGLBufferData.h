#ifndef OPENGL_OPENGLBUFFERDATA_H_
#define OPENGL_OPENGLBUFFERDATA_H_

#include "../World.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

struct vertex {
	float x;
	float y;
	float z;
	float textureX;
	float textureY;

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
	void addCellVertices(Cell *cell);
	std::vector<vertex> vertices;
	std::vector<GLuint> indices;
	GLuint verticesToUpdate;
	GLuint indicesToUpate;
	float objectTextureSize;

};

#endif
