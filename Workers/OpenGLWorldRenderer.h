#ifndef OPENGLWORLDRENDERER_H
#define OPENGLWORLDRENDERER_H

#include <WorldWorker.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "../Visualization/OpenGLControls.h"



class OpenGLWorldRenderer: public WorldWorker {
public:
	OpenGLWorldRenderer(World *world);
	virtual ~OpenGLWorldRenderer();

	 void work(World* world) override;
	//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void prepareMapData(World *world);
	GLuint  bindData(const std::vector <GLfloat> & vertices);
	void bindMatrices(GLuint shaderProgram);
	void createMatrices();
	void tempUpdate();
	void init();

	static void updateView();



	static void ex(){
std::cout<<"qqqqqqqqqq";
	};


private:


	std::vector <GLfloat> mapVerices;
	std::vector <GLfloat> mapColor;
	 int mapDataSize;
	std::vector <float> mapCenter{2};
	GLuint mapVAO;
	GLuint mvpMatrixID;
	glm::mat4 mvpMatrix;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	float angleView;


};

#endif // OPENGLWORLDRENDERER_H
