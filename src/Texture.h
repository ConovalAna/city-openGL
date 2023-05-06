#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <string>

class Texture {
private:
	unsigned int textureID;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, bPP;

public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
};