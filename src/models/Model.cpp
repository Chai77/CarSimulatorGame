#include "Model.h"

void Model::initVAO() {
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->nrOfVertices, this->vertices, GL_STATIC_DRAW);

	if(nrOfIndices > 0) {
		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->nrOfIndices, this->indices, GL_STATIC_DRAW);
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
}

Model::Model(Vertex* vertices, int nrOfVertices, GLint* indices, int nrOfIndices) {
	this->nrOfVertices = nrOfVertices;
	this->nrOfIndices = nrOfIndices;

	this->vertices = new Vertex[this->nrOfVertices];
	for(int i = 0; i < nrOfVertices; i++) {
		this->vertices[i] = vertices[i];
	}

	this->indices = new GLint[this->nrOfIndices];
	for(int i = 0; i < nrOfIndices; i++) {
		this->indices[i] = indices[i];
	}

	this->initVAO();
}

Model::~Model() {
}

void Model::render() {
	glBindVertexArray(this->VAO);
	if(this->nrOfIndices > 0) {
		glDrawElements(GL_TRIANGLES, this->nrOfIndices, GL_UNSIGNED_INT, 0);
	} else {
		glDrawArrays(GL_TRIANGLES, 0, this->nrOfVertices);
	}
	glBindVertexArray(0);
}
