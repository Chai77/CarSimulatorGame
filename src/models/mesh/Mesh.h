#ifndef MODELS_MESH_MESH_H_
#define MODELS_MESH_MESH_H_

#include <GL/glew.h>
#include "../Vertex.h"
#include "../../shaders/Shader.h"

#include <glm.hpp>
#include <vec3.hpp>
#include <vec2.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/matrix_transform.hpp>

class Mesh {
private:
	Vertex* vertices;
	int nrOfVertices;
	GLuint* indices;
	int nrOfIndices;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	glm::mat4 ModelMatrix;

	void initVAO();

	void updateModelMatrix();

public:
	Mesh(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices,
		glm::vec3 position=glm::vec3(0.f), glm::vec3 rotation=glm::vec3(0.f),
		glm::vec3 scale=glm::vec3(1.f));
	Mesh(Mesh& mesh);
	virtual ~Mesh();

	virtual void render(Shader* shader);
	virtual void update();
	virtual void updateUniforms(Shader* shader);

	Vertex* getVertices();
	int getNrOfVertices();
	GLuint* getIndices();
	int getNrOfIndices();

	glm::vec3 getPosition();
	glm::vec3 getScale();
	glm::vec3 getRotation();

	void rotate(glm::vec3 rotation);
	void move(glm::vec3 position);
	void scaleUp(glm::vec3 scale);
};

#endif /* MODELS_MESH_MESH_H_ */
