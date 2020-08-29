#include "Mesh.h"

void Mesh::initVAO() {
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->nrOfVertices * sizeof(Vertex), this->vertices, GL_STATIC_DRAW);

	if(nrOfIndices > 0) {
		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->nrOfIndices * sizeof(GLuint), this->indices, GL_STATIC_DRAW);
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

void Mesh::updateModelMatrix() {
	this->ModelMatrix = glm::mat4(1.f);
	this->ModelMatrix = glm::translate(this->ModelMatrix, this->position);
	this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.x), glm::vec3(1.f, 0.f, 0.f));
	this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.y), glm::vec3(0.f, 1.f, 0.f));
	this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->rotation.z), glm::vec3(0.f, 0.f, 1.f));
	this->ModelMatrix = glm::scale(this->ModelMatrix, this->scale);
}

void Mesh::updateUniforms(Shader* shader) {
	shader->setMat4f("ModelMatrix", this->ModelMatrix);
}

Mesh::Mesh(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices,
		glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {
	this->nrOfIndices = nrOfIndices;
	this->nrOfVertices = nrOfVertices;

	this->vertices = new Vertex[nrOfVertices];
	for(int i = 0; i < nrOfVertices; i++) {
		this->vertices[i] = vertices[i];
	}

	this->indices = new GLuint[nrOfIndices];
	for(int i = 0; i < nrOfIndices; i++) {
		this->indices[i] = indices[i];
	}

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	this->initVAO();
	this->updateModelMatrix();
}

Mesh::Mesh(Mesh& mesh) {
	this->nrOfVertices = mesh.getNrOfVertices();
	this->nrOfIndices = mesh.getNrOfVertices();

	this->vertices = new Vertex[nrOfVertices];
	for(int i = 0; i < this->nrOfVertices; i++) {
		this->vertices[i] = mesh.getVertices()[i];
	}

	this->indices = new GLuint[nrOfIndices];
	for(int i = 0; i < this->nrOfIndices; i++) {
		this->indices[i] = mesh.getIndices()[i];
	}

	this->position = mesh.getPosition();
	this->scale = mesh.getScale();
	this->rotation = mesh.getRotation();

	this->initVAO();
	this->updateModelMatrix();
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Mesh::render(Shader* shader) {
	glBindVertexArray(this->VAO);
	updateUniforms(shader);
	shader->use();
	if(this->nrOfIndices > 0) {
		glDrawElements(GL_TRIANGLES, this->nrOfIndices, GL_UNSIGNED_INT, 0);
	} else {
		glDrawArrays(GL_TRIANGLES, 0, this->nrOfVertices);
	}
	glBindVertexArray(0);
}

void Mesh::update() {
	updateModelMatrix();
}

Vertex* Mesh::getVertices() {
	return this->vertices;
}

int Mesh::getNrOfVertices() {
	return this->nrOfVertices;
}

GLuint* Mesh::getIndices() {
	return this->indices;
}

int Mesh::getNrOfIndices() {
	return this->nrOfIndices;
}

glm::vec3 Mesh::getPosition() {
	return position;
}

glm::vec3 Mesh::getScale() {
	return scale;
}

glm::vec3 Mesh::getRotation() {
	return rotation;
}

void Mesh::move(glm::vec3 position) {
	this->position = this->position + position;
}

void Mesh::rotate(glm::vec3 rotation) {
	this->rotation = this->rotation + rotation;
}

void Mesh::scaleUp(glm::vec3 scale) {
	this->scale = this->scale + scale;
}
