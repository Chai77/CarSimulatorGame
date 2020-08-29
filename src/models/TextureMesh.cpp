#include "TextureMesh.h"

TextureMesh::TextureMesh(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices,
			Texture* texture) :
			Mesh(vertices, nrOfVertices, indices, nrOfIndices) {
	this->texture = texture;
}

TextureMesh::TextureMesh(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices,
			const char* fileName) :
			Mesh(vertices, nrOfVertices, indices, nrOfIndices) {
	this->texture = new Texture(fileName);
}

TextureMesh::TextureMesh(TextureMesh& mesh) :
		Mesh(mesh.getVertices(), mesh.getNrOfVertices(), mesh.getIndices(), mesh.getNrOfIndices()) {
	this->texture = mesh.getTexture();
}

TextureMesh::~TextureMesh() {
}

void TextureMesh::render(Shader* shader) {
	this->texture->bind(0);
	Mesh::render(shader);
	this->texture->unbind();
}

void TextureMesh::updateUniforms(Shader* shader) {
	Mesh::updateUniforms(shader);
	shader->seti("modelTexture", 0);
}

Texture* TextureMesh::getTexture() {
	return texture;
}

