#include "OpenGLTexture.h"

OpenGLTexture::OpenGLTexture(GLenum textureTarget, const std::string &filePath) {
	_filePath = filePath;
	_textureTarget = textureTarget;

}

void OpenGLTexture::loadTexture() {
	glGenTextures(1, &textureObject);
	glBindTexture(_textureTarget, textureObject);
	unsigned char *image = SOIL_load_image(_filePath.c_str(), &imageWidth, &imageHeight, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB,
	GL_UNSIGNED_BYTE,
					image);
	SOIL_free_image_data(image);
	glTexParameteri(_textureTarget, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(_textureTarget, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(_textureTarget);
	glBindTexture(_textureTarget,0);

}

void OpenGLTexture::bindTexture(GLenum textureUnit){
	glActiveTexture(textureUnit);
	glBindTexture(_textureTarget,textureObject);
}
OpenGLTexture::~OpenGLTexture() {
	glDeleteTextures(1,&textureObject);
}

