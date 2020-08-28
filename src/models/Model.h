#ifndef MODELS_MODEL_H_
#define MODELS_MODEL_H_

#include <vector>
#include <iostream>

#include <GL/glew.h>
#include "Vertex.h"

class Model {
private:
	Vertex* vertices;
	int nrOfVertices;
	GLint* indices;
	int nrOfIndices;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	void initVAO();

public:
	Model(Vertex* vertices, int nrOfVertices, GLint* indices, int nrOfIndices);
	~Model();

	void render();
};

#endif /* MODELS_MODEL_H_ */
