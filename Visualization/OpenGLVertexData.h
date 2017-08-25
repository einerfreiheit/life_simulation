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

	OpenGLVertexData(){};
	~OpenGLVertexData(){};

	GLuint vertexBufferObject=0;
	GLuint indexBufferObject=0;
	GLuint vertexNumber=0;

	std::vector<vertex> vertices;
	std::vector<GLuint> vertexIndices;
	float textureDecrease = 1 / 128.0;

};

#endif
