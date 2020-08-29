#ifndef MODELS_TEXTUREMESH_H_
#define MODELS_TEXTUREMESH_H_

#include "Model.h"
#include "../textures/Texture.h"
#include "../shaders/Shader.h"

class TextureMesh: public Mesh {
private:
	Texture* texture;
public:
	TextureMesh(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices,
			Texture* texture);
	TextureMesh(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices,
			const char* fileName);
	TextureMesh(TextureMesh& mesh);
	~TextureMesh();

	void updateUniforms(Shader* shader) override;

	void render(Shader* shader) override;

	Texture* getTexture();
};

#endif /* MODELS_TEXTUREMESH_H_ */
