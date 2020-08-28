#ifndef TEXTURES_TEXTURE_H_
#define TEXTURES_TEXTURE_H_

#include <GL/glew.h>

class Texture {
private:
	GLint texture;

	void getTextureFromFile(const char* fileName);
public:
	Texture(const char* fileName);
	~Texture();

	void render();
};

#endif /* TEXTURES_TEXTURE_H_ */
