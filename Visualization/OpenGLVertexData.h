#ifndef VISUALIZATION_OPENGLVERTEXDATA_H_
#define VISUALIZATION_OPENGLVERTEXDATA_H_

#include  "../World.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

	struct vertex {
		glm::vec3 vertexPosition;
		glm::vec2 textureUV;
	};

class OpenGLVertexData {
public:

	OpenGLVertexData();
	~OpenGLVertexData();

	virtual void update(World *world);
	virtual void computeBuffersData(World *world)=0;


	GLsizei elementNumber;
	GLuint vertexBufferObject;
	GLuint indexBufferObject;
	GLuint vertexNumber;

	std::vector<vertex> vertices;
	std::vector<GLuint> vertexIndices;
	float textureDecrease = 1 / 128.0;

};

#endif
