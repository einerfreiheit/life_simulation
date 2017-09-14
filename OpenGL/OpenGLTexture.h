#ifndef OPENGL_OPENGLTEXTURE_H_
#define OPENGL_OPENGLTEXTURE_H_

#include "SOIL/SOIL.h"
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class OpenGLTexture  {
public:
	OpenGLTexture(GLenum textureTarget, const std::string &filePath);
	virtual ~OpenGLTexture();

	void loadTexture();
	void bindTexture(GLenum textureUnit);
private:
	GLuint textureObject;
	GLenum _textureTarget;
	std::string _filePath;
	int imageWidth;
	int imageHeight;
};

#endif
