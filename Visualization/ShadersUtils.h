#ifndef VISUALIZATION_SHADERSUTILS_H_
#define VISUALIZATION_SHADERSUTILS_H_

#include <GL/glew.h>
#include <string>

class ShadersUtils {
public:

	static GLuint loadShaders(const char *vertexFilePath, const char *fragmentFilePath);

private:
	static std::string readFile(const char *filePath);
	static GLuint createShader(GLenum type, const char *shaderSource);

};

#endif
