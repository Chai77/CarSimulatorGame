#include "Texture.h"

void Texture::getTextureFromFile(const char* fileName) {
	int width;
	int height;
	int channels;
	unsigned char* image = SOIL_load_image(fileName, &width, &height, &channels, 0);
	if(!image) {
		std::stringstream stream;
		stream << "There was an error loading the texture file " << fileName << "\n";
		throw std::runtime_error(stream.str());
	}
	glGenTextures(1, &this->texture);
	glBindTexture(GL_TEXTURE_2D, this->texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(image);
}

Texture::Texture(const char* fileName) {
	getTextureFromFile(fileName);
}

Texture::~Texture() {
	glDeleteTextures(1, &this->texture);
}

void Texture::bind(int unit) {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, this->texture);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}
