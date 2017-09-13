#include "../OpenGL/ShadersUtils.h"

#include <iostream>
#include <fstream>
#include <vector>

std::string ShadersUtils::readFile(const char *filePath) {
	std::string result;
	std::string line;
	std::ifstream inputStream;
	inputStream.open(filePath, std::ios::in);
	if (!inputStream.is_open()) {
		throw std::runtime_error("cannot open file in: " + *filePath);
	}
	while (!inputStream.eof()) {
		std::getline(inputStream, line);
		result += line + "\n";

	}
	inputStream.close();
	return result;

}

GLuint ShadersUtils::loadShaders(const char *vertexFilePath, const char *fragmentFilePath) {

	GLuint vertexShader = createShader(GL_VERTEX_SHADER, vertexFilePath);
	GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentFilePath);
	std::cout << "linking program\n";
	GLint success = 0;
	std::vector<char> errorLog;
	int errorLogSize = 0;

	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);



	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &errorLogSize);
		errorLog.resize(errorLogSize);
		glGetProgramInfoLog(program, errorLog.size(), NULL, &errorLog.front());
		throw std::runtime_error(&errorLog.front());
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	std::cout << "shader program is Ok\n";

	return program;

}

GLuint ShadersUtils::createShader(GLenum type, const char *filePath) {

	std::string shaderText = readFile(filePath);
	const char *shaderP = shaderText.c_str();
	std::cout << "compiling " << filePath << std::endl;
	GLuint shaderId = glCreateShader(type);
	glShaderSource(shaderId, 1, &shaderP, NULL);

	GLint success = 0;
	std::vector<char> errorLog;
	int errorLogSize = 0;

	glCompileShader(shaderId);
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &errorLogSize);
		errorLog.resize(errorLogSize);
		glGetShaderInfoLog(shaderId, errorLog.size(), NULL, &errorLog.front());
		throw std::runtime_error(&errorLog.front());
	}

	return shaderId;
}
