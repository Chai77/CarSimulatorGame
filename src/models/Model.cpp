#include "Model.h"

#include "../textures/Texture.h"

Model::Model(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices) {
	Mesh* mesh = new Mesh(vertices, nrOfVertices, indices, nrOfIndices);
	meshes.push_back(mesh);
}

Model::Model(std::vector<Mesh*> meshes) {
	for(auto& mesh : meshes) {
		if(TextureMesh* inputTextureMesh = dynamic_cast<TextureMesh*>(mesh)) {
			TextureMesh* textureMesh = new TextureMesh(*inputTextureMesh);
			textures.push_back(textureMesh->getTexture());
			this->meshes.push_back(textureMesh);
		} else {
			this->meshes.push_back(new Mesh(*mesh));
		}
	}
}

Model::~Model() {
	for(auto*& mesh : meshes) {
		delete mesh;
	}
	for(auto*& texture : textures) {
		delete texture;
	}
}

void Model::render(Shader* shader) {
	for(auto& mesh : meshes) {
		mesh->render(shader);
	}
}

void Model::update() {
	for(auto& mesh : meshes) {
		mesh->update();
	}
}

void Model::rotate(glm::vec3 rotation) {
	for(auto& mesh : meshes) {
		mesh->rotate(rotation);
	}
}

void Model::move(glm::vec3 position) {
	for(auto& mesh : meshes) {
		mesh->move(position);
	}
}
