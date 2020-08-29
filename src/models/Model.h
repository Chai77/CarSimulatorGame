#ifndef MODELS_MODEL_H_
#define MODELS_MODEL_H_

#include <GL/glew.h>
#include <vector>
#include "Vertex.h"
#include "../shaders/Shader.h"
#include "mesh/Mesh.h"
#include "TextureMesh.h"
#include "../textures/Texture.h"

#include <glm.hpp>
#include <vec3.hpp>
#include <vec2.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>

class Model {
private:
	std::vector<Mesh*> meshes;
	std::vector<Texture*> textures;
public:
	Model(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices);
	Model(std::vector<Mesh*> meshes);
	~Model();

	void render(Shader* shader);
	void update();

	void move(glm::vec3 position);
	void scaleUp(glm::vec3 scale);
	void rotate(glm::vec3 rotation);
};

#endif /* MODELS_MODEL_H_ */
