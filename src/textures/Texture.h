#ifndef TEXTURES_TEXTURE_H_
#define TEXTURES_TEXTURE_H_

#include <GL/glew.h>
#include <SOIL2.h>
#include <stdexcept>
#include <sstream>

class Texture {
private:
	GLuint texture;

	void getTextureFromFile(const char* fileName);
public:
	Texture(const char* fileName);
	~Texture();

	void bind(int unit);
	void unbind();
};

#endif /* TEXTURES_TEXTURE_H_ */
