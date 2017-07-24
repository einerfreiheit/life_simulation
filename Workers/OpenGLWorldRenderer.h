#ifndef OPENGLWORLDRENDERER_H
#define OPENGLWORLDRENDERER_H

#include <WorldWorker.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "../Visualization/OpenGLControls.h"
#include <SOIL/SOIL.h>

class OpenGLWorldRenderer: public WorldWorker {
public:
	OpenGLWorldRenderer(World *world);
	virtual ~OpenGLWorldRenderer();
	void work(World* world) override;


private:
	void prepareMapData(World *world);
	void setHeightDepth(World *world, float &maxHeight, float &minHeight);
	void bindMatrices(GLuint shaderProgram);
	void createMatrices();
	void init();
	void getTextureCoord(const float &vertexPosX, const float &vertexPosY,
			float &textureX, float &textureY);
	void loadTexture(std::string filePath);
	void bindTextures();

	float textureX;
	float textureY;
	GLuint shaderProgram;
	GLuint groundTexture;
	GLuint snowTexture;
	GLfloat * mapDataPtr;
	int imageHeight;
	int imageWidth;
	GLfloat intensity;
	float minHeight;
	float maxHeight;
	std::vector<float> mapCenter { 2 };
	GLuint mvpMatrixID;
	glm::mat4 mvpMatrix;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;


};

#endif
