#include "Texture.h"
#include <glut.h>
#include <GL/gl.h>
#include <windows.h>
#include <Eigen/Core>
#include "stb_image.h"
#define GL_GLEXT_PROTOTYPES

Texture::Texture(const std::string& path)
	: textureID(0), filePath(path), localBuffer(nullptr), width(0), height(0), bPP(0)
{
	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(path.c_str(), &width, &height, &bPP, 4);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (localBuffer) {
		stbi_image_free(localBuffer);
	}
}

Texture::~Texture() {
	glDeleteTextures(1, &textureID);
}

void Texture::Bind(unsigned int slot) const {
	//glActiveTexture(GL_TEXTURE0+slot);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::Unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}