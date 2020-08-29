#include "Renderer.h"

Renderer::Renderer(Shader* shader) {
	this->shader = shader;
}

Renderer::~Renderer() {
	delete this->shader;
}

void Renderer::prepare() {
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Renderer::renderModels(std::vector<Model*> models) {
	this->shader->use();
	for (auto& model : models) {
		model->render(this->shader);
	}
	this->shader->unuse();
}

void Renderer::setUniforms(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix) {
	this->shader->setMat4f("ViewMatrix", ViewMatrix);
	this->shader->setMat4f("ProjectionMatrix", ProjectionMatrix);
}
